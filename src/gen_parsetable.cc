#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <boost/regex.hpp>

int main(int argc, char *argv[])
{
    using ::std::string;
    using ::std::cout;
    using ::std::endl;
    using ::std::ifstream;
    using ::std::ofstream;
    using ::std::istringstream;
    using ::std::ostringstream;
    using ::std::getline;
    using ::boost::regex;
    using ::boost::regex_match;
    using ::boost::regex_replace;
    string infile = "";
    string outfile = "";
    string header = "PARSETABLE";
    if (argc == 2)
    {
        infile = argv[1];
        outfile = "";
    }
    else if (argc == 3)
    {
        infile = argv[1];
        outfile = argv[2];
    }
    else if (argc == 4)
    {
        infile = argv[1];
        outfile = argv[2];
        header = argv[3];
    }
    if (infile != "")
    {
        ifstream ifs(infile, ifstream::in);
        ostringstream oss;
        oss << "#ifndef " << header << endl
            << "#define " << header << endl << endl
            << "#include <string>" << endl << endl;
        int row, col;
        ifs >> row >> col;
        int ter, non;
        ifs >> ter >> non;
        oss << "constexpr int kParsingTableRow = " << row << ";" << endl
            << "constexpr int kParsingTableCol = " << col << ";" << endl << endl
            << "struct ParsingTableCell" << endl
            << "{" << endl
            << "  int oper;" << endl
            << "  int state;" << endl
            << "};" << endl << endl;
        string *str = new string[col];
        for (int i = 0; i < col; ++i)
            ifs >> str[i];
        oss << "const ::std::string kTokenIndex[] = {" << endl;
        for (int i = 0; i < col; ++i)
            oss << "  \"" << str[i] << "\"," << endl;
        oss << "};" << endl << endl;
        oss << "const ParsingTableCell kParsingTable[][" << col << "] = " << endl
            << "{" << endl;
        regex reS("S\\d*");
        regex reR("R\\d*");
        regex reL("/");
        for (int i = 0; i < row; ++i)
        {
            string s;
            int r;
            char c;
            ifs >> r >> c;
            oss << "  { /* State: " << i << " */" << endl;
            for (int j = 0; j < col; ++j)
            {
                ifs >> s;
                char p = s[0];
                int cv = -1;
                int co = -1;
                if (regex_match(s, reR, ::boost::regex_constants::match_continuous) &&
                    regex_match(s, reS, ::boost::regex_constants::match_continuous))
                {
                    s = regex_replace(s, reR, "", ::boost::regex_constants::match_continuous);
                    s = regex_replace(s, reL, "", ::boost::regex_constants::match_continuous);
                }
                cv = atoi(s.substr(1, s.length() - 1).c_str());
                switch (p)
                {
                case '-':
                    cv = -1;
                    break;
                case 'S':
                    co = 0;
                    break;
                case 'R':
                    co = 1;
                    break;
                case 'G':
                    co = 2;
                    break;
                case 'A':
                    co = -2;
                    cv = -2;
                }
                oss << "    { " << co << ", " << cv << " }," << endl;
            }
            oss << "  }," << endl;
        }
        ifs.close();
        oss << "};" << endl << endl
            << "#endif  // " << header << endl;
        if (outfile != "")
        {
            ofstream ofs(outfile, ofstream::out);
            ofs << oss.str();
            ofs.close();
        }
        else
        {
            cout << oss.str();
        }
    }
    return 0;
}
