#include <stack>
#include "parser.h"
#include "parsetree.h"
#include <string>
#include <iostream>

inline int TokenToInt(Token token);

Parser::Parser()
{
    scanner_ = nullptr;
}

Parser::~Parser()
{
}

bool Parser::Parsing(ParseNode **tree_out)
{
    using ::std::cout;
    using ::std::endl;
    using ::std::string;
    cout << "Start parsing" << endl;
    ::std::stack<ParsingStackCell> stack;
    ::std::stack<ParseNode*> node_stack;
    Token token_scan = scanner_->ScanNext();
    ParseNode *node;
    ParseNode *tmp_node;
    cout << "scan: " << token_scan.name << "(" << token_scan.value << ")" << endl;
    Token token_tmp;
    ParsingStackCell cell;
    ::std::vector<ParseNode*> v;
    cell.state = 0;
    stack.push(cell);
    int n;
    int state = 0;
    string value = "";
    while (true)
    {
        cout << "state: " << state << endl;
        switch (kParsingTable[state][TokenToInt(token_scan)].oper)
        {
        case 0: // S
            cell.state = kParsingTable[state][TokenToInt(token_scan)].state;
            cell.token = token_scan;
            node = new ParseNode();
            node->value = cell.token.name;
            tmp_node = new ParseNode();
            tmp_node->value = cell.token.value;
            node->child.push_back(tmp_node);
            cout << "push: " << cell.token.name << "(" << cell.token.value << ")" << endl;
            stack.push(cell);
            node_stack.push(node);
            token_scan = scanner_->ScanNext();
            cout << "scan: " << token_scan.name << "(" << token_scan.value << ")" << endl;
            break;
        case 1: // R
            n = kGrammar[kParsingTable[state]
                        [TokenToInt(token_scan)].state - 1].num_terms;
            value = "";
            v.clear();
            if (n <= (int)stack.size())
            {
                while (n--)
                {
                    v.push_back(node_stack.top());
                    value += stack.top().token.name + "(" + stack.top().token.value + ")";
                    cout << "pop: " << stack.top().token.name << "(" << stack.top().token.value << ")" << endl;
                    stack.pop();
                    node_stack.pop();
                }
            }
            else
                return false;
            token_tmp.name = kGrammar[
                    kParsingTable[state][TokenToInt(token_scan)].state - 1].nonterminal;
            cell.state = kParsingTable[stack.top().state][TokenToInt(token_tmp)].state;
            cell.token.name = kGrammar[
                    kParsingTable[state][TokenToInt(token_scan)].state - 1].nonterminal;
            cell.token.value = value;
            node = new ParseNode();
            node->value = cell.token.name;
            if (v.size() > 0)
            {
                node->child = v;
            }
            else
            {
                tmp_node = new ParseNode();
                tmp_node->value = "";
                node->child.push_back(tmp_node);
            }
            cout << "push: " << cell.token.name << "(" << cell.token.value << ")" << endl;
            stack.push(cell);
            node_stack.push(node);
            break;
        case -2: // Accept
            *tree_out = node_stack.top();
            return true;
        default: // Reject
            return false;
        }
        state = stack.top().state;
    }
    return false;
}

inline int TokenToInt(Token token)
{
    for (int i = 0; i < kParsingTableCol; ++i)
    {
        if (token.name == kTokenIndex[i]) return i;
    }
    return -1;
}
