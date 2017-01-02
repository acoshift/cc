#ifndef CC_PARSER_H_
#define CC_PARSER_H_

#include "token.h"
#include "scanner.h"
#include "parsetable.h"
#include "grammar.h"
#include "parsetree.h"

class Parser
{
public:
    Parser();
    ~Parser();
    void set_scanner(Scanner* scanner) { scanner_ = scanner; }
    Scanner* scanner() const { return scanner_; }
    bool Parsing(ParseNode **tree_out);
private:
    struct ParsingStackCell
    {
        Token token;
        int state;
    };
    Scanner* scanner_;
};

#endif  // CC_PARSER_H_
