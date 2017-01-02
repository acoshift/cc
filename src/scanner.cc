#include "scanner.h"
#include "tokentable.h"
#include "error.h"
#include <string>

// using ::std::string;

inline bool IsMatch(::std::string::iterator begin, ::std::string::iterator end,
                    int *output);
inline bool MayMatch(::std::string::iterator begin, ::std::string::iterator end);

Scanner::Scanner()
{
    index_ = 0;
    length_ = 0;
    input_ = "";
}

Scanner::~Scanner()
{
}

void Scanner::set_input(::std::string input)
{
    input_ = input;
    index_ = 0;
    length_ = input_.length();
}

Token Scanner::ScanNext()
{
    Token token;
    if (index_ < length_)
    {
        int len_str = -1;
        int pos_token = -1;
        int max_pos_token = -1;
        for (int i = 1; i <= length_ - index_; ++i)
        {
            if (IsMatch(input_.begin() + index_, input_.begin() + index_ + i,
                        &pos_token))
            {
                if (len_str < i)
                {
                    len_str = i;
                    max_pos_token = pos_token;
                }
            }
            if (!MayMatch(input_.begin() + index_,
                          input_.begin() + index_ + i + 1))
            {
                break;
            }
        }
        if (len_str != -1)
        {
            if (kTokenTable[pos_token].name.substr(0, 8) != "__SKIP__")
            {
                token.name = kTokenTable[max_pos_token].name;
                token.value = input_.substr(index_, len_str);
                index_ += len_str;
                return token;
            }
            else
            {
                index_ += len_str;
                return ScanNext();
            }
        }
    }
    token.name = "$";
    token.value = "$";
    if (index_ < length_) error("Scanner Error");
    return token;
}

inline bool IsMatch(::std::string::iterator begin, ::std::string::iterator end,
                    int *output)
{
    for (int i = 0; i < kTokenTableCount; ++i)
    {
        if (::boost::regex_match(begin, end, kTokenTable[i].regex))
        {
            *output = i;
            return true;
        }
    }
    return false;
}

inline bool MayMatch(::std::string::iterator begin, ::std::string::iterator end)
{
    for (int i = 0; i < kTokenTableCount; ++i)
    {
        if (::boost::regex_match(begin, end, kTokenTable[i].regex,
                                 boost::regex_constants::match_partial))
        {
            return true;
        }
    }
    return false;
}
