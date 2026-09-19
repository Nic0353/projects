#include "Block.h"
#include "Statement.h"

void Block::interpret(Context& c){
    for(auto i:statementList){
        i->interpret(c);
    }
}
Block::~Block(){
    for(auto i:statementList){
        delete i;
    }
}