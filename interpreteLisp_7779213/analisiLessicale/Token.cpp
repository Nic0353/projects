#include <iostream>
#include "Token.h"

std::ostream& operator<<(std::ostream & os, const Token & t){
    os<<"("<<Token::tag2string[t.tag]<<","<<t.word<<",row:"<<t.row<<")\n";
    return os;
}
