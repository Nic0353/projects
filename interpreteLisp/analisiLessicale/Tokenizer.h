#if !defined(TOKENIZER_H)
#define TOKENIZER_H

#include <vector>
#include "Token.h"
#include "LexicalExceptions.h"
class Tokenizer{
public:
    Tokenizer() = default;
    Tokenizer(Tokenizer const& tok) = delete;
    ~Tokenizer() = default;

    Tokenizer& operator= (Tokenizer const&) = delete;
    std::vector<Token> operator() (std::ifstream& inputFile){
        std::vector<Token>inputTokens;
        tokenizeFile(inputFile,inputTokens);
        return inputTokens;

    } 
private:
    void tokenizeFile(std::ifstream& inputFile, std::vector<Token>& inputTokens);
    void tokenize_id_or_constant(std::string& temp, int row,std::vector<Token>& inputTokens);


};

#endif