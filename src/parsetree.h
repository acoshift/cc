#ifndef CC_PARSETREE_H_
#define CC_PARSETREE_H_

#include <vector>
#include <string>
#include "token.h"

struct ParseNode
{
    ::std::string value;
    ParseNode *top;
    ::std::vector<ParseNode*> child;
};

#endif  // CC_PARSETREE_H_
