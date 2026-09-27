#if !defined(NUM_EXPRESSION_H)
#define NUM_EXPRESSION_H

#include "Context.h"
#include <stdexcept>
#include <cstdint>
#include <string>
class NumExpr{
public:
    virtual ~NumExpr() = default ;
    virtual int64_t interpret(Context const& c) const = 0;


};

class Number:public NumExpr{
public:
    Number() = default;
    Number(Number const& v) = delete;
    Number(int64_t v):value{v} {};
    ~Number() = default;
    Number& operator=(Number const& other) = default;

    void setValue(int64_t v){
        value = v;
    }
    int64_t getValue()const{
        return value;
    }

    int64_t interpret(Context const& c) const;

private:
    int64_t  value;
};

class Operator:public NumExpr{
public:
    enum opCode{ADD,SUB,MUL,DIV};
    Operator() = default;
    Operator(Operator const& ope) = delete;
    Operator(opCode o, NumExpr* l, NumExpr* r):op{o},left{l},right{r} {};
    ~Operator();
    Operator& operator=(Operator const& o) = default;
    int64_t interpret(Context const& c) const;

    NumExpr* getRight() const{
        return right;
    }
    NumExpr* getLeft() const{
        return left;
    }
    opCode getOp()const{
        return op;
    }
    void setOp(opCode o){
        op = o;
    }
    void setRight(NumExpr* r){
        right = r;
    }
    void setLeft(NumExpr* l){
        left = l;
    }
    static opCode strToOpCode(std::string s){
        if(s == "ADD") return ADD;
        if(s == "SUB") return SUB;
        if(s == "MUL") return MUL;
        if(s == "DIV") return DIV;
        std::stringstream err;
        err<<"Unknown parameter in strToOpCode function";
        throw(SyntaxError(err.str()));
    }

private:
    NumExpr* left;
    NumExpr* right;
    opCode op;

};



class Variable:public NumExpr{
public:
    Variable() = default; 
    Variable (Variable const& v) = delete;
    Variable(std::string const& id): identifier{id} {};
    ~Variable() = default;
    Variable& operator=(Variable const& v) = default;
    int64_t interpret(Context const& c) const;

    std::string const& getIdentifier()const{
        return identifier;
    }
private:
    std::string identifier;

};

#endif