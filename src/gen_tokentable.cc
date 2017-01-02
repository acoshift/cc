#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

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
    string infile = "";
    string outfile = "";
    string header = "TOKENTABLE";
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
        int count = 0;
        oss << "#ifndef " << header << endl
            << "#define " << header << endl << endl
            << "#include <string>" << endl
            << "#include <boost/regex.hpp>" << endl << endl
            << "struct TokenTableCell" << endl
            << "{" << endl
            << "  ::std::string name;" << endl
            << "  ::boost::regex regex;" << endl
            << "};" << endl << endl
            << "const TokenTableCell kTokenTable[] = " << endl
            << "{" << endl;
        while (!ifs.eof())
        {
            string s;
            getline(ifs, s);
            if (s == "") continue;
            oss << "  { \"";
            for (char c : s)
            {
                if (c == '\r' || c == '\n') continue;
                switch (c)
                {
                case '\\':
                    oss << "\\\\";
                    break;
                case '\'':
                    oss << "\\\'";
                    break;
                case '\"':
                    oss << "\\\"";
                    break;
                case ' ':
                    oss << "\", ::boost::regex(\"";
                    break;
                default:
                    oss << c;
                }
            }
            oss << "\") }," << endl;
            ++count;
        }
        ifs.close();
        oss << "};" << endl << endl
            << "constexpr int kTokenTableCount = " << count << ";" << endl << endl
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

