#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#define fixS(s) (s[0] == '#' ? s.substr(1, s.length()) : s)

int main(int argc, char *argv[])
{
    using ::std::string;
    using ::std::ifstream;
    using ::std::ofstream;
    using ::std::istringstream;
    using ::std::ostringstream;
    using ::std::cout;
    using ::std::endl;
    using ::std::getline;
    string infile = "";
    string outfile = "";
    string header = "GRAMMAR";
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
            << "#include <string>" << endl << endl
            << "struct GrammarCell" << endl
            << "{" << endl
            << "    ::std::string nonterminal;" << endl
            << "    int num_terms;" << endl
            << "};" << endl << endl
            << "const GrammarCell kGrammar[] = " << endl
            << "{" << endl;
        while (!ifs.eof())
        {
            string s;
            getline(ifs, s);
            if (s == "") continue;
            istringstream iss(s);
            iss >> s;
            int n = 0;
            oss << "  { \"" << fixS(s) << "\", ";
            while (iss >> s) ++n;
            oss << n << " }," << endl;
            ++count;
        }
        ifs.close();
        oss << "};" << endl << endl
            << "const int kGrammarCount = " << count << ";" << endl << endl
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
