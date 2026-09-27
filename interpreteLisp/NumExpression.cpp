#include "NumExpression.h"

int64_t Number::interpret(Context const& c)const{
    return value;
}
Operator::~Operator(){
    delete left;
    delete right;
}
int64_t Operator::interpret(Context const& c) const{
    int64_t lval = left->interpret(c);
    int64_t rval = right->interpret(c);
    switch (op){
        case(ADD): return lval+rval;
        case(SUB): return lval-rval;
        case(MUL): return lval*rval;
        case(DIV): 
            if(rval==0){
                std::stringstream err;
                err<<"Error: division by zero  ";
                throw(DivisionByZero(err.str()));
            }
            return lval/rval;
        default:
            std::stringstream err;
            err<<"Invalid operator passed as a parameter  ";
            throw(InvalidOperatorAsParameter(err.str()));
    }
}
int64_t Variable::interpret(Context const& c) const{
    try{
        return c.getNumValue(identifier);
    }
    catch(VariableNotFound& e){
        std::stringstream err;
        err<<"Error: variable '"<<identifier<<"' was not initialized";
        throw(VariableNotFound(err.str()));
    }
    catch(std::exception& e){
        std::stringstream err;
        err<<"Something wrong ";
        throw(err.str());
    }
}
