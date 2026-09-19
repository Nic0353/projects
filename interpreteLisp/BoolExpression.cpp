#include "BoolExpression.h"

bool BoolConst::interpret(Context const& c) const{
    return bo;
}
BoolOp::~BoolOp(){
    delete left;
    delete right;
}
bool BoolOp::interpret(Context const& c)const{
    bool lval = left->interpret(c);
    bool rval;
    switch(op){
        case(AND): 
            if(lval == false){ // condizione per fare in modo che AND sia cortocircuitato
                return false;
            }
            rval = right->interpret(c);
            return lval&&rval;
        case(OR):
            if(lval == true){ // condizione per fare in modo che OR sia cortocircuitato
                return true;
            }
            rval = right->interpret(c);
            return lval||rval;
        case(NOT):
            return !lval;
        default: 
            std::stringstream err;
            err<<"Invalid operator passed as a parameter  ";
            throw(InvalidOperatorAsParameter(err.str()));
    }

}
RelOp::~RelOp(){
    delete left;
    delete right;
}
bool RelOp::interpret(Context const& c)const{
    long long int lval = left->interpret(c);
    long long int rval = right->interpret(c);

    switch(op){
        case(LT):
            if(lval<rval){return true;}
            else{return false;}
        case(GT):
            if(lval>rval){return true;}
            else{return false;}
        case(EQ):
            if(lval==rval){return true;}
            else{return false;}
        default:
            std::stringstream err;
            err<<"Invalid operator passed as a parameter  ";
            throw(InvalidOperatorAsParameter(err.str()));
    }

}