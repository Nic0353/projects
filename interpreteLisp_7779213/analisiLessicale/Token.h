#if !defined(TOKEN_H)
#define TOKEN_H

#include <string>

class Token{
public:
    static constexpr int LP = 0; 
    static constexpr int RP = 1; 
    static constexpr int BLOCK = 2; 
    static constexpr int INPUT = 3;
    static constexpr int SET = 4; 
    static constexpr int PRINT = 5;
    static constexpr int IF = 6;
    static constexpr int WHILE = 7; 
    static constexpr int ADD = 8; 
    static constexpr int SUB = 9;
    static constexpr int MUL = 10;
    static constexpr int DIV = 11;
    static constexpr int LT = 12; 
    static constexpr int GT = 13;
    static constexpr int EQ = 14;
    static constexpr int AND = 15;
    static constexpr int OR = 16;
    static constexpr int NOT = 17;
    static constexpr int TRUE = 18;
    static constexpr int FALSE = 19;
    static constexpr int CONST = 20;
    static constexpr int ID = 21;



    static constexpr int numberOfID = 22;

    static constexpr const char* id2word[]{
        "(",")","BLOCK","INPUT","SET","PRINT","IF","WHILE","ADD","SUB","MUL","DIV",
        "LT","GT","EQ","AND","OR","NOT","TRUE","FALSE","CONST","ID"
    };
    static constexpr const char* tag2string[]{ 
        "LP","RP","BLOCK","INPUT","SET","PRINT","IF","WHILE","OP","OP","OP","OP",
        "BOOL_EXPR","BOOL_EXPR","BOOL_EXPR","BOOL_EXPR","BOOL_EXPR","BOOL_EXPR","BOOL","BOOL",
        "CONST","ID"
    };
    
    Token() = default; 
    Token(Token const& tok) = default;
    ~Token() = default;
    Token& operator=(Token const&) = default;

    Token(int t, char* w): tag{t}, word{w} {};
    Token(int t, std::string w,int r): tag{t}, word{w},row{r} {};

    int tag;
    std::string word;
    int row;
};

//overloading  dell'output stream
std::ostream& operator<<(std::ostream & os, const Token & t);

#endif