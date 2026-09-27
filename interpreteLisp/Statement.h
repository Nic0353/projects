#if !defined(STATEMENT_H)
#define STATEMENT_H
#include <string>
#include "NumExpression.h"
#include "BoolExpression.h"
#include "Context.h"

class Block;
//i costruttori di copia sono tutti "delete" perchè non vengono mai utilizzati, inoltre se venissero utilizzati potrebbero causare problemi con la distruzione degli oggetti
//perchè gli oggetti derivati da statement hanno dei puntatori ad altri oggetti quindi se creo una copia di un oggetto derivato da statement, i puntatori dell'oggetto verrebbero copiati e se poi chiamassi il distruttore di uno dei due oggetti derivati da statement, che sono uno la copia dell'altro, andrei la prima volta a cancellare gli oggetti che punta effettivamente, però la seconda volta non so cosa andrà a fare dato che gli oggetti a cui punta sono già stati cancellati
class Statement{
public:
    virtual ~Statement() = default;
    virtual void interpret(Context& c) = 0;


};
class Set : public Statement{
public:
    Set() = default; 
    Set(Set const& s) = delete;
    ~Set();
    void interpret(Context& c) override;
    void setId(Variable* i){
        id = i;
    }
    void setValue(NumExpr* n){
        value = n;
    }

private:
    Variable* id;
    NumExpr* value;

};

class Input : public Statement{
public:
    Input() = default;
    Input(Input const& i) = delete;
    ~Input();
    Input(std::string const& v):id{new Variable(v)} {};
    void interpret(Context& c) override;
    void setId(Variable* i){
        id = i;
    }
private:
    Variable* id;
};

class Print : public Statement{
public:
    Print() = default;
    Print(Print const& p) = delete;
    ~Print();
    Print(NumExpr* v):value{v} {};
    void interpret(Context& c) override;
    void setValue(NumExpr* v){
        value = v;
    }
private:
    NumExpr* value;

};

class If : public Statement{
public:
    If() = default;
    If(If const& f) = delete;
    ~If();
    void interpret(Context& c) override;
    void setCondition(BoolExpr* b){
        condition = b;
    }
    void setBlock1(Block* b){
        block1 = b;
    }
    void setBlock2(Block* b){
        block2 = b;
    }

private:
    BoolExpr* condition;
    Block* block1;
    Block* block2;

};

class While:  public Statement{
public:
    While() = default;
    While(While const& w) = delete;
    ~While();
    void interpret(Context& c) override;
    void setCondition(BoolExpr* b){
        condition = b;
    }
    void setBlock(Block* b){
        block = b;
    }

private:
    BoolExpr* condition;
    Block* block;

};



#endif