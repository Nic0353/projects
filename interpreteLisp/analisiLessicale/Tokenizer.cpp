#include "Tokenizer.h"
#include <fstream>
#include <sstream>
#include <iostream>
void Tokenizer::tokenize_id_or_constant(std::string& temp, int row,std::vector<Token>& inputTokens){
    
    if(isdigit(temp.at(0)) || temp.at(0) == '-'){ // se questa condizione è verifcata supongo sia un numero
    //gestisco le singole cifre
        if(temp.length() == 1){
            if(temp.at(0) == '-'){
                std::stringstream err;
                err<<"lexical error at line: "<<row<<"\n";
                throw LexicalError(err.str());
            }
            else{
                inputTokens.emplace_back(Token{Token::CONST,temp,row});
            }
        }
        else{
            if((temp.at(0) == '-' && (temp.at(1)>='1' && temp.at(1)<='9'))||(temp.at(0)>='1' && temp.at(0)<='9') ){// per ora è valido, qualsiasi cosa sia diversa non è valida
                for(int i = 1;i<temp.length();++i){
                    if(!isdigit(temp[i])){
                        std::stringstream err;
                        err<<"invalid number at line: "<<row<<"\n";
                        throw LexicalError(err.str());
                    }
                }
                inputTokens.emplace_back(Token{Token::CONST,temp,row});

            }
            else{// qualsiasi cosa di verso 
                std::stringstream err;
                err<<"invalid number at line: "<<row<<"\n";
                throw LexicalError(err.str());
            }
        }
    }
    else{// suppongo sia l'id di una variabile
        for (char c: temp){
            if(!isalpha(c)){
                std::stringstream err;
                err<<"invalid id at line: "<<row<<"\n";
                throw LexicalError(err.str());
            }
        }
        inputTokens.emplace_back(Token{Token::ID,temp,row});
    }
    return;



}

void Tokenizer::tokenizeFile(std::ifstream& inputFile, std::vector<Token>& inputTokens){
    char ch;
    ch = inputFile.get();
    std::string temp;
    bool found{false};
    int rowCount{1};
    while(!inputFile.eof()){
        found = false;
        if (isspace(ch)){
            if(ch == '\n'){++rowCount;}
        }
        else if(ch == '('){
            inputTokens.emplace_back(Token{Token::LP,Token::id2word[Token::LP],rowCount});
        }
        else if(ch == ')'){
            inputTokens.emplace_back(Token{Token::RP,Token::id2word[Token::RP],rowCount});
        }
        else if(isalpha(ch) ||(ch =='-') || isdigit(ch)){
            while(!isspace(ch) && ch!='(' && ch!=')' && ch!=EOF){
                temp+=ch;
                ch = inputFile.get();
            }
            inputFile.unget();
            for(int i = 0; i<Token::numberOfID-2;++i){ // il -2 serve per escludere CONST e ID
                if(temp == Token::id2word[i]){
                    inputTokens.emplace_back(Token{i,Token::id2word[i],rowCount});
                    found = true;
                    temp.erase();
                    break;
                }
            }
            
            if(found == false){
                tokenize_id_or_constant(temp,rowCount,inputTokens);
                temp.erase();
            }
        }
        else{
            std::stringstream err;
            err<< "Stray character " << ch<< " in input at line " << rowCount;
            throw LexicalError(err.str());
        }
        ch = inputFile.get();
    }
    if (inputTokens.size() == 0){
        std::stringstream err;
        err<<"Empty file";
        throw LexicalError(err.str());
    }
    return;
}