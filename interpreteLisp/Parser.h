#if !defined(PARSER_H)
#define PARSER_H
#include "Exceptions.h"

#include "Block.h"
#include <vector>
#include "analisiLessicale/Tokenizer.h"
#include "Statement.h"
#include "BoolExpression.h"
class Parser{
public:
    static constexpr int BLOCK = 0;
    static constexpr int STATEMENT = 1;
    static constexpr int NUM_EXPR = 2;
    static constexpr int BOOL_EXPR = 3;
    Parser() = default;
    Parser(Parser const& p) = delete;
    ~Parser() = default;
    Block* parse(std::vector<Token>& inputTokens,int start,int stop);// il valore di ritorno è il nodo radice che in base alla grammatica è un BLOCK
    
private:
    int recursiveParsing(std::vector<Token>& inputTokens, int start,Block* node);
    int parenthesisCloseAt(std::vector<Token>& inputTokens, int start);
    NumExpr* BuildNumExpr(std::vector<Token>& inputTokens, int start, int stop);
    BoolExpr* BuildBoolExpr(std::vector<Token>& inputTokens,int start,int stop);

};
#endif