#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "scanner.h"
#include "parser.h"
#include "parsetree.h"

::std::string PrintTree(ParseNode *node);

int main(int argc, char *argv[])
{
    using ::std::string;
    using ::std::ifstream;
    using ::std::ofstream;
    using ::std::ostringstream;
    using ::std::cout;
    using ::std::endl;
    string infile = "";
    if (argc == 2)
    {
        infile = argv[1];
    }
    else
    {
        cout << "No input file" << endl;
        return 0;
    }
    ifstream ifs(infile, ifstream::in);
    ostringstream oss;
    oss << ifs.rdbuf();
    string input = oss.str();
    Scanner *scanner = new Scanner();
    scanner->set_input(input);

    Parser *parser = new Parser();
    parser->set_scanner(scanner);

    ParseNode *tree;

    cout << (parser->Parsing(&tree) == true ? "Accept" : "Reject") << endl;

    cout << PrintTree(tree) << endl;

    /*while (true)
    {
        Token s = scanner->ScanNext();
        if (s.name != "$")
            //cout << s.Value << endl;
            cout << "::" << s.name << endl << s.value << endl << endl;
        else break;
    }*/

    return 0;
}

::std::string PrintTree(ParseNode *node)
{
    ::std::string result = node->value;
    if (node->child.size() > 0)
    {
        result += "(";
        for (auto p = node->child.rbegin(); p != node->child.rend(); ++p)
            result += PrintTree(*p);
        result += ")";
    }
    return result;
}

