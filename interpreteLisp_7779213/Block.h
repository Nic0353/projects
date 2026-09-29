#if !defined(BLOCK_H)
#define BLOCK_H
#include <vector>
#include "Context.h"
class Statement;
class Block{
public:
    Block() = default;
    Block(Block const& b) = delete; //il costruttore utilizzato non viene mai utilizzato in questo programma
    ~Block();
    void interpret(Context& c) ;
    void addStatement(Statement* b){statementList.emplace_back(b);}

private:
    std::vector<Statement*>statementList;


};

#endif