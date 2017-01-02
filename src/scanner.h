#ifndef CC_SCANNER_H_
#define CC_SCANNER_H_

#include <string>
#include "token.h"

class Scanner
{
    // using ::std::string;
public:
    Scanner();
    ~Scanner();
    void set_input(::std::string input);
    ::std::string input() const { return input_; }
    Token ScanNext();
private:
    int index_;
    int length_;
    ::std::string input_;
};

#endif  // CC_SCANNER_H_

