#include "Statement.h"
#include "Exceptions.h"
#include "analisiLessicale/Token.h"
#include "Context.h"
#include <sstream>
#include <iostream>
#include "Block.h"
#include <string>
Set::~Set(){
    delete id;
    delete value;
}
void Set::interpret(Context& c){
    for(int i = 0; i<20;++i){ // conto fino a 20 perchè ci sono 20 keyword che non possono essere utilizzate, sono le prime 20 definite in Token.h
        if(id->getIdentifier() == Token::id2word[i]){
            std::stringstream err;
            err<<"Error: keyword found in SET statement";
            throw(SyntaxError(err.str()));
        }
    }
    // vado a controllare se il membro di destra è una variabile, se lo è controllo che sia già stata definita
    if(dynamic_cast<Variable*>(value) != nullptr){
         //allora si tratta di una variabile
        Variable* v = dynamic_cast<Variable*>(value);

        try{
            c.getNumValue(v->getIdentifier()); 
        }
        catch(VariableNotFound& e){
            std::stringstream err;
            err<<"Error: variable  '"<<v->getIdentifier()<<"' was not initialized";
            throw(VariableNotFound(err.str()));
        }
    }

    //se il programma arriva a questo punto posso aggiungere o aggiornare la variabile in Context
    c.setNumValue(id->getIdentifier(),value->interpret(c));
    return; 
}
Input::~Input(){
    delete id;
}
void Input::interpret(Context& c){

    for(int i = 0; i<20;++i){ // conto fino a 20 perchè ci sono 20 keyword che non possono essere utilizzate, sono le prime 20 definite in Token.h
        if(id->getIdentifier() == Token::id2word[i]){
            std::stringstream err;
            err<<"Error: keyword found in INPUT statement";
            throw(VariableNotFound(err.str()));
        }
    }
    int64_t intInput;
    std::string strInput;
    std::getline(std::cin,strInput);
    //devo togliere gli spazi dopo la l'ultima cifra(nel caso ci fossero) dato che uso getline
    const std::string spaces = " \t\n\r\f\v";
    size_t end = strInput.find_last_not_of(spaces);

    if (end != std::string::npos) { 
        strInput.erase(end + 1);
    } else {
        strInput.clear();// se end è uguale ad npos significa che non ha trovato uno spazio alla fine
    }

    if(isdigit(strInput.at(0)) || strInput.at(0) == '-'){ // se questa condizione è verificata supongo sia un numero
    //gestisco le singole cifre
        if(strInput.length() == 1){
            if(strInput.at(0) == '-'){
                std::stringstream err;
                err<<"Error: invalid input value";
                throw(InvalidInputValue(err.str()));
            }
            
        }
        else{
            if((strInput.at(0) == '-' && (strInput.at(1)>='1' && strInput.at(1)<='9'))||(strInput.at(0)>='1' && strInput.at(0)<='9') ){// per ora è valido, qualsiasi cosa sia diversa non è valida
                for(int i = 1;i<strInput.length();++i){
                    if(!isdigit(strInput[i])){
                        std::stringstream err;
                        err<<"Error: invalid input value";
                        throw(InvalidInputValue(err.str()));
                    }
                }

            }
            else{ 
                std::stringstream err;
                err<<"Error: invalid input value";
                throw(InvalidInputValue(err.str()));
            }
        }
    }
    
    try{
        intInput = stoll(strInput);
    }
    catch(std::invalid_argument& e){
        std::stringstream err;
        err<<"Error: snvalid input value";
        throw(InvalidInputValue(err.str()));
    }
    catch(std::exception& e){
        std::stringstream err;
        err<<"Error: something wrong in the INPUT instruction";
        throw(err.str());
    }    
    c.setNumValue(id->getIdentifier(),intInput);
    return;
}
Print::~Print(){
    delete value;
}
void Print::interpret(Context& c){
    std::cout<< value->interpret(c)<<std::endl;
}
If::~If(){
    delete condition;
    delete block1;
    delete block2;
}
void If::interpret(Context& c) {
    if(condition->interpret(c) == true){
        block1->interpret(c);
    }
    else{
        block2->interpret(c);
    }
}
While::~While(){
    delete condition;
    delete block;
}
void While::interpret(Context& c){
    while(condition->interpret(c) == true){
        block->interpret(c);
    }
}


