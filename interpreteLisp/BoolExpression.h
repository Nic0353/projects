#if !defined(BOOL_EXPRESSION_H)
#define BOOL_EXPRESSION_H
#include "Exceptions.h"
#include <iostream>
#include <string>
#include "Context.h"
#include "NumExpression.h"
#include <sstream>
class BoolExpr{
public:
    virtual ~BoolExpr() = default;
    virtual bool interpret(Context const& c) const = 0;
};

class BoolConst:public BoolExpr{
public:

    BoolConst() = default;
    BoolConst(BoolConst const& b): bo{b.bo} {};
    BoolConst(std::string b):bo{stringtoBoolType(b)} {};
    ~BoolConst() = default;
    void setBool(bool b){
        bo = b;
    }

    static bool stringtoBoolType(std::string b){
        if(b=="TRUE") return true;
        if(b == "FALSE") return false;
        std::stringstream err;
        err<<"Unknown parameter in stringtoBoolType function";
        throw(SyntaxError(err.str()));
    }
    bool interpret(Context const& c) const;
private:
    bool bo;

};

class BoolOp: public BoolExpr{
public:
    enum opCode{AND,OR,NOT}; //il NOT ignora il membro di destra

    BoolOp() = default;
    BoolOp(BoolOp const& o):op{o.op}, left{o.left},right{o.right}{};
    BoolOp(std::string b, BoolExpr* l, BoolExpr* r):op{strToOpCode(b)},left{l},right{r} {};
    ~BoolOp();
    BoolExpr*  getLeft()const{
        return left;
    }
    BoolExpr*  getRight()const{
        return right;
    }
    opCode getOpCode()const{
        return op;
    }
    void setLeft(BoolExpr* l){
        left = l;
    }
    void setRight(BoolExpr* r){
        right = r;
    }
    void setOpCode(opCode o){
        op = o;
    }
    bool interpret(Context const& c) const;

    static opCode strToOpCode(const std::string& b){
        if(b=="AND")return AND;
        else if(b=="OR")return OR;
        else if(b == "NOT") return NOT;
        std::stringstream err;
        err<<"Unknown parameter in strToOpCode function";
        throw(SyntaxError(err.str()));
    }

private:
    BoolExpr* left;
    BoolExpr* right;
    opCode op;
    
};


class RelOp:public BoolExpr{
public:
    enum opCode{LT,GT,EQ};
    RelOp() = default;
    RelOp(RelOp const& r):left{r.left},right{r.right},op{r.op}{};
    RelOp(std::string b, NumExpr* l, NumExpr* r):op{strToOpCode(b)},left{l},right{r} {};
    ~RelOp();

    NumExpr* getLeft()const{
        return left;
    }
    NumExpr* getRight()const{
        return right;
    }
    opCode getOpCode()const{
        return op;
    }
    void setLeft(NumExpr* l){
        left = l;
    }
    void setRight(NumExpr* r){
        right = r;
    }
    void setOpCode(opCode o){
        op = o;
    }

    bool interpret(Context const& c) const;



    static opCode strToOpCode(std::string b){
        if(b=="LT"){return LT;}
        if(b=="GT"){return GT;}
        if(b=="EQ"){return EQ;}
        std::stringstream err;
        err<<"Unknown parameter in strToOpCode function";
        throw(SyntaxError(err.str()));
    }
    
private:
    NumExpr* left;
    NumExpr* right;
    opCode op;

};



#endif