#include "Parser.h"
#include "analisiLessicale/Token.h"
#include "Exceptions.h"
#include <sstream>
BoolExpr* Parser::BuildBoolExpr(std::vector<Token>& inputTokens,int start,int stop){
    int localStop;
    if(inputTokens.at(start).tag == Token::LT){
        RelOp* returnOp = new RelOp();
        returnOp->setOpCode(returnOp->strToOpCode("LT"));

        if(inputTokens.at(start+1).tag == Token::LP){
            localStop = parenthesisCloseAt(inputTokens,start+2);
            returnOp->setLeft(BuildNumExpr(inputTokens,start+2,localStop));
        }
        else if(inputTokens.at(start+1).tag == Token::CONST){
            returnOp->setLeft(new Number(stoll(inputTokens.at(start+1).word)));
            localStop = start+1;
        }
        else if(inputTokens.at(start+1).tag == Token::ID){
            returnOp->setLeft(new Variable(inputTokens.at(start+1).word));
            localStop = start+1;
        }
        else{
            //errore
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start+1).row<<", malformed boolean expression, numerical expression not found in LT operator \n";
            throw(SyntaxError(err.str()));
        }
        start = localStop;

        if(inputTokens.at(start+1).tag == Token::LP){
            localStop = parenthesisCloseAt(inputTokens,start+2);
            returnOp->setRight(BuildNumExpr(inputTokens,start+2,localStop));
        }
        else if(inputTokens.at(start+1).tag == Token::CONST){
            returnOp->setRight(new Number(stoll(inputTokens.at(start+1).word)));
            localStop = start+1;
        }
        else if(inputTokens.at(start+1).tag == Token::ID){
            returnOp->setRight(new Variable(inputTokens.at(start+1).word));
            localStop = start+1;
        }
        else{
            //errore
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start+1).row<<", malformed boolean expression, numerical expression not found in LT operator \n";
            throw(SyntaxError(err.str()));

        }
        start = localStop;
        ++start;
        if(stop!=start){
        std::stringstream err;
        err<<"Error on line: "<<inputTokens.at(start).row<<", expected right parenthesis to close boolean expression\n";
        throw(SyntaxError(err.str()));
        }
        return returnOp;

    }
    else if(inputTokens.at(start).tag == Token::GT){
        RelOp* returnOp = new RelOp();
        returnOp->setOpCode(returnOp->strToOpCode("GT"));

        if(inputTokens.at(start+1).tag == Token::LP){
            localStop = parenthesisCloseAt(inputTokens,start+2);
            returnOp->setLeft(BuildNumExpr(inputTokens,start+2,localStop));
        }
        else if(inputTokens.at(start+1).tag == Token::CONST){
            returnOp->setLeft(new Number(stoll(inputTokens.at(start+1).word)));
            localStop = start+1;
        }
        else if(inputTokens.at(start+1).tag == Token::ID){
            returnOp->setLeft(new Variable(inputTokens.at(start+1).word));
            localStop = start+1;
        }
        else{
            //errore
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start+1).row<<", malformed boolean expression, numerical expression not found in GT operator \n";
            throw(SyntaxError(err.str()));
        }
        start = localStop;

        if(inputTokens.at(start+1).tag == Token::LP){
            localStop = parenthesisCloseAt(inputTokens,start+2);
            returnOp->setRight(BuildNumExpr(inputTokens,start+2,localStop));
        }
        else if(inputTokens.at(start+1).tag == Token::CONST){
            returnOp->setRight(new Number(stoll(inputTokens.at(start+1).word)));
            localStop = start+1;
        }
        else if(inputTokens.at(start+1).tag == Token::ID){
            returnOp->setRight(new Variable(inputTokens.at(start+1).word));
            localStop = start+1;
        }
        else{
            //errore
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start+1).row<<", malformed boolean expression, numerical expression not found in GT operator \n";
            throw(SyntaxError(err.str()));
        }        
        start = localStop;
        ++start;
        if(stop!=start){
        std::stringstream err;
        err<<"Error on line: "<<inputTokens.at(start).row<<", expected right parenthesis to close boolean expression\n";
        throw(SyntaxError(err.str()));
        }
        return returnOp;

    }
    else if(inputTokens.at(start).tag == Token::EQ){
        RelOp* returnOp = new RelOp();
        returnOp->setOpCode(returnOp->strToOpCode("EQ"));

        if(inputTokens.at(start+1).tag == Token::LP){
            localStop = parenthesisCloseAt(inputTokens,start+2);
            returnOp->setLeft(BuildNumExpr(inputTokens,start+2,localStop));
        }
        else if(inputTokens.at(start+1).tag == Token::CONST){
            returnOp->setLeft(new Number(stoll(inputTokens.at(start+1).word)));
            localStop = start+1;
        }
        else if(inputTokens.at(start+1).tag == Token::ID){
            returnOp->setLeft(new Variable(inputTokens.at(start+1).word));
            localStop = start+1;
        }
        else{
            //errore
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start+1).row<<", malformed boolean expression, numerical expression not found in EQ operator \n";
            throw(SyntaxError(err.str()));
        }
        start = localStop;

        if(inputTokens.at(start+1).tag == Token::LP){
            localStop = parenthesisCloseAt(inputTokens,start+2);
            returnOp->setRight(BuildNumExpr(inputTokens,start+2,localStop));
        }
        else if(inputTokens.at(start+1).tag == Token::CONST){
            returnOp->setRight(new Number(stoll(inputTokens.at(start+1).word)));
            localStop = start+1;
        }
        else if(inputTokens.at(start+1).tag == Token::ID){
            returnOp->setRight(new Variable(inputTokens.at(start+1).word));
            localStop = start+1;
        }
        else{
            //errore
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start+1).row<<", malformed boolean expression, numerical expression not found in EQ operator \n";
            throw(SyntaxError(err.str()));
        }
        start = localStop;
        ++start;
        if(stop!=start){
        std::stringstream err;
        err<<"Error on line: "<<inputTokens.at(start).row<<", expected right parenthesis to close boolean expression\n";
        throw(SyntaxError(err.str()));
        }
        return returnOp;
    }

    else if(inputTokens.at(start).tag == Token::AND){
        BoolOp* returnOp = new BoolOp();
        returnOp->setOpCode(returnOp->strToOpCode("AND"));

        if(inputTokens.at(start+1).tag == Token::LP){
            localStop = parenthesisCloseAt(inputTokens,start+2);
            returnOp->setLeft(BuildBoolExpr(inputTokens,start+2,localStop));
        }
        else if(inputTokens.at(start+1).tag == Token::TRUE){
            localStop = start+1;
            returnOp->setLeft(new BoolConst("TRUE"));
        }
        else if(inputTokens.at(start+1).tag == Token::FALSE){
            localStop = start+1;
            returnOp->setLeft(new BoolConst("FALSE"));
        }
        else{
            //errore
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start+1).row<<", malformed boolean expression, operator: AND \n";
            throw(SyntaxError(err.str()));
        }
        start = localStop;
        if(inputTokens.at(start+1).tag == Token::LP){
            localStop = parenthesisCloseAt(inputTokens,start+2);
            returnOp->setRight(BuildBoolExpr(inputTokens,start+2,localStop));
        }
        else if(inputTokens.at(start+1).tag == Token::TRUE){
            localStop = start+1;
            returnOp->setRight(new BoolConst("TRUE"));
        }
        else if(inputTokens.at(start+1).tag == Token::FALSE){
            localStop = start+1;
            returnOp->setRight(new BoolConst("FALSE"));
        }
        else{
            //errore
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start+1).row<<", malformed boolean expression, operator: AND \n";
            throw(SyntaxError(err.str()));
        }
        start = localStop;
        ++start;
        if(stop!=start){
        std::stringstream err;
        err<<"Error on line: "<<inputTokens.at(start).row<<", expected right parenthesis to close boolean expression\n";
        throw(SyntaxError(err.str()));
        }
        return returnOp;
    }
    else if(inputTokens.at(start).tag == Token::OR){
        BoolOp* returnOp = new BoolOp();
        returnOp->setOpCode(returnOp->strToOpCode("OR"));

        if(inputTokens.at(start+1).tag == Token::LP){
            localStop = parenthesisCloseAt(inputTokens,start+2);
            returnOp->setLeft(BuildBoolExpr(inputTokens,start+2,localStop));
        }
        else if(inputTokens.at(start+1).tag == Token::TRUE){
            localStop = start+1;
            returnOp->setLeft(new BoolConst("TRUE"));
        }
        else if(inputTokens.at(start+1).tag == Token::FALSE){
            localStop = start+1;
            returnOp->setLeft(new BoolConst("FALSE"));
        }
        else{
            //errore
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start+1).row<<", malformed boolean expression: operator: OR \n";
            throw(SyntaxError(err.str()));
        }
        start = localStop;
        if(inputTokens.at(start+1).tag == Token::LP){
            localStop = parenthesisCloseAt(inputTokens,start+2);
            returnOp->setRight(BuildBoolExpr(inputTokens,start+2,localStop));
        }
        else if(inputTokens.at(start+1).tag == Token::TRUE){
            localStop = start+1;
            returnOp->setRight(new BoolConst("TRUE"));
        }
        else if(inputTokens.at(start+1).tag == Token::FALSE){
            localStop = start+1;
            returnOp->setRight(new BoolConst("FALSE"));
        }
        else{
            //errore
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start+1).row<<", malformed boolean expression, operator: OR \n";
            throw(SyntaxError(err.str()));
        }
        start = localStop;
        ++start;
        if(stop!=start){
        std::stringstream err;
        err<<"Error on line: "<<inputTokens.at(start).row<<", expected right parenthesis to close boolean expression\n";
        throw(SyntaxError(err.str()));
        }
        return returnOp;
    }
    else if(inputTokens.at(start).tag == Token::NOT){
        BoolOp* returnOp = new BoolOp();
        returnOp->setOpCode(returnOp->strToOpCode("NOT"));

        if(inputTokens.at(start+1).tag == Token::LP){
            localStop = parenthesisCloseAt(inputTokens,start+2);
            returnOp->setLeft(BuildBoolExpr(inputTokens,start+2,localStop));
        }
        else if(inputTokens.at(start+1).tag == Token::TRUE){
            localStop = start+1;
            returnOp->setLeft(new BoolConst("TRUE"));
        }
        else if(inputTokens.at(start+1).tag == Token::FALSE){
            localStop = start+1;
            returnOp->setLeft(new BoolConst("FALSE"));
        }
        else{
            //errore
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start+1).row<<", malformed boolean expression, operator: NOT \n";
            throw(SyntaxError(err.str()));
        }
        start = localStop;
        ++start;
        if(stop!=start){
        std::stringstream err;
        err<<"Error on line: "<<inputTokens.at(start).row<<", expected right parenthesis to close boolean expression\n";
        throw(SyntaxError(err.str()));
        }
        return returnOp;
    }
    else if(inputTokens.at(start).tag == Token::FALSE|| inputTokens.at(start).tag == Token::TRUE){
        BoolConst* returnOp = new BoolConst();
        if(inputTokens.at(start).tag == Token::FALSE){
            returnOp->setBool(false);
        }
        else{
            returnOp->setBool(true);
        }
        return returnOp;
    }
    
    else{
        //errore
        std::stringstream err;
        err<<"Error on line: "<<inputTokens.at(start).row<<", boolean expression not found \n";
        throw(SyntaxError(err.str()));
    }
    
    return nullptr;
}

NumExpr* Parser::BuildNumExpr(std::vector<Token>& inputTokens, int start,int stop){
    int tempStop;
    Operator* returnNumExpr = new Operator();
    if(inputTokens.at(start).tag == Token::ADD){
        returnNumExpr->setOp(returnNumExpr->strToOpCode("ADD"));
        ++start;
        if(inputTokens.at(start).tag == Token::LP){
            ++start;
            tempStop = parenthesisCloseAt(inputTokens,start);
            returnNumExpr->setLeft(BuildNumExpr(inputTokens,start,tempStop));
        }
        else if(inputTokens.at(start).tag == Token::CONST || inputTokens.at(start).tag == Token::ID){
            tempStop = start;
            returnNumExpr->setLeft(BuildNumExpr(inputTokens,start,tempStop));
        }
        else{
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start).row<<" invalid numerical expression";
            throw(SyntaxError(err.str()));
        }
        start = tempStop+1;
        if(inputTokens.at(start).tag == Token::LP){
            ++start;
            tempStop = parenthesisCloseAt(inputTokens,start);
            returnNumExpr->setRight(BuildNumExpr(inputTokens,start,tempStop));
        }
        else if(inputTokens.at(start).tag == Token::ID || inputTokens.at(start).tag == Token::CONST){
            tempStop = start;
            returnNumExpr->setRight(BuildNumExpr(inputTokens,start,tempStop));
        }
        else{
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start).row<<" invalid numerical expression";
            throw(SyntaxError(err.str()));
        }
        start = tempStop;
        ++start;
        if(start != stop){
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start-1).row<<"missing right parenthesis ) to close ADD operator";
            throw(SyntaxError(err.str()));
        }

    }
    else if(inputTokens.at(start).tag == Token::SUB){
        returnNumExpr->setOp(returnNumExpr->strToOpCode("SUB"));
        ++start;
        if(inputTokens.at(start).tag == Token::LP){
            ++start;
            tempStop = parenthesisCloseAt(inputTokens,start);
            returnNumExpr->setLeft(BuildNumExpr(inputTokens,start,tempStop));
        }
        else if(inputTokens.at(start).tag == Token::CONST || inputTokens.at(start).tag == Token::ID){
            tempStop = start;
            returnNumExpr->setLeft(BuildNumExpr(inputTokens,start,tempStop));
        }
        else{
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start).row<<" invalid numerical expression";
            throw(SyntaxError(err.str()));
        }
        start = tempStop+1;
        if(inputTokens.at(start).tag == Token::LP){
            ++start;
            tempStop = parenthesisCloseAt(inputTokens,start);
            returnNumExpr->setRight(BuildNumExpr(inputTokens,start,tempStop));
        }
        else if(inputTokens.at(start).tag == Token::ID || inputTokens.at(start).tag == Token::CONST){
            tempStop = start;
            returnNumExpr->setRight(BuildNumExpr(inputTokens,start,tempStop));
        }
        else{
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start).row<<" invalid numerical expression";
            throw(SyntaxError(err.str()));
        }
        start = tempStop;
        ++start;
        if(start != stop){
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start-1).row<<"missing right parenthesis ) to close SUB operator";
            throw(SyntaxError(err.str()));
        }
    }
    else if(inputTokens.at(start).tag == Token::MUL){
        returnNumExpr->setOp(returnNumExpr->strToOpCode("MUL"));
        ++start;
        if(inputTokens.at(start).tag == Token::LP){
            ++start;
            tempStop = parenthesisCloseAt(inputTokens,start);
            returnNumExpr->setLeft(BuildNumExpr(inputTokens,start,tempStop));
        }
        else if(inputTokens.at(start).tag == Token::ID || inputTokens.at(start).tag == Token::CONST){
            tempStop = start;
            returnNumExpr->setLeft(BuildNumExpr(inputTokens,start,tempStop));
        }
        else{
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start).row<<" invalid numerical expression";
            throw(SyntaxError(err.str()));
        }
        start = tempStop+1;
        if(inputTokens.at(start).tag == Token::LP){
            ++start;
            tempStop = parenthesisCloseAt(inputTokens,start);
            returnNumExpr->setRight(BuildNumExpr(inputTokens,start,tempStop));
        }
        else if(inputTokens.at(start).tag == Token::CONST || inputTokens.at(start).tag == Token::ID){
            tempStop = start;
            returnNumExpr->setRight(BuildNumExpr(inputTokens,start,tempStop));
        }
        else{
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start).row<<" invalid numerical expression";
            throw(SyntaxError(err.str()));
        }
        start = tempStop;
        ++start;
        if(start != stop){
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start-1).row<<"missing right parenthesis ) to close MUL operator";
            throw(SyntaxError(err.str()));
        }
    }
    else if(inputTokens.at(start).tag == Token::DIV){
        returnNumExpr->setOp(returnNumExpr->strToOpCode("DIV"));
        ++start;
        if(inputTokens.at(start).tag == Token::LP){
            ++start;
            tempStop = parenthesisCloseAt(inputTokens,start);
            returnNumExpr->setLeft(BuildNumExpr(inputTokens,start,tempStop));
        }
        else if(inputTokens.at(start).tag == Token::CONST || inputTokens.at(start).tag == Token::ID){
            tempStop = start;
            returnNumExpr->setLeft(BuildNumExpr(inputTokens,start,tempStop));
        }
        else{
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start).row<<" invalid numerical expression";
            throw(SyntaxError(err.str()));
        }
        start = tempStop+1;
        if(inputTokens.at(start).tag == Token::LP){
            ++start;
            tempStop = parenthesisCloseAt(inputTokens,start);
            returnNumExpr->setRight(BuildNumExpr(inputTokens,start,tempStop));
        }
        else if(inputTokens.at(start).tag == Token::CONST || inputTokens.at(start).tag == Token::ID){
            tempStop = start;
            returnNumExpr->setRight(BuildNumExpr(inputTokens,start,tempStop));
        }
        else{
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start).row<<" invalid numerical expression";
            throw(SyntaxError(err.str()));
        }
        start = tempStop;
        ++start;
        if(start != stop){
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start-1).row<<"missing right parenthesis ) to close DIV operator";
            throw(SyntaxError(err.str()));
        }
    }
    else if(inputTokens.at(start).tag == Token::ID){
        Variable* returnVariable = new Variable(inputTokens.at(start).word);
        delete returnNumExpr;
        return returnVariable;
        
    }
    else if(inputTokens.at(start).tag == Token::CONST){
        Number* returnNumber = new Number(stoll(inputTokens.at(start).word));
        delete returnNumExpr;
        return returnNumber;
    }
    else{
        std::stringstream err;
        err<<"Error on line: "<<inputTokens.at(start).row<<"numerical expression not found";
        throw(SyntaxError(err.str()));
    }
    return returnNumExpr;
}












int Parser::parenthesisCloseAt(std::vector<Token>& inputTokens, int start){
    int parenthesisCount = 1; 
    int stop = start;
    while(parenthesisCount != 0){
        ++stop;
        if(inputTokens.at(stop).tag == Token::LP){
            ++parenthesisCount;
        }
        else if(inputTokens.at(stop).tag == Token::RP){
            --parenthesisCount;
        }
    }
    return stop;
}


int Parser::recursiveParsing(std::vector<Token>& inputTokens, int start,Block* node){//in questa funzione vengono costruiti gli statement che poi  vengono "connessi" al blocco node
    //i valori di input sono: lo stream di tokens, il blocco srtart che si suppone sia una keyword di uno statement e il puntatore al blocco node a cui collegare gli statementù
    
    int expectedStop = parenthesisCloseAt(inputTokens,start);//vado a calcolare la parentesi che chiude lo statement
    int tempStop;
    if(inputTokens.at(start).tag == Token::INPUT){
        Input* statement = new Input();
        node->addStatement(statement);
        ++start;
        if(inputTokens.at(start).tag == Token::ID){
            statement->setId(new Variable(inputTokens.at(start).word));
            ++start;
        }
        else{
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start).row<<" variable_id not found in INPUT statement";
            throw(SyntaxError(err.str()));
        }
        if(start!=expectedStop){
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start).row<<" missing right parenthesis ) to close INPUT statement";
            throw(SyntaxError(err.str()));
        }
    }
    else if(inputTokens.at(start).tag == Token::PRINT){
        Print* statement = new Print();
        node->addStatement(statement);
        ++start;
        if(inputTokens.at(start).tag == Token::LP){
            ++start;
            tempStop = parenthesisCloseAt(inputTokens,start);
        }
        else{
            tempStop = start;
        }
        statement->setValue(BuildNumExpr(inputTokens,start,tempStop));
        start = tempStop;
        ++start;
        if(start!=expectedStop){
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start).row<<" missing right parenthesis ) to close PRINT statement";
            throw(SyntaxError(err.str()));
        }
    }
    else if(inputTokens.at(start).tag == Token::SET){
        Set* statement = new Set();
        node->addStatement(statement);
        ++start;
        if(inputTokens.at(start).tag == Token::ID){
            statement->setId(new Variable(inputTokens.at(start).word));
        }
        else{
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start).row<<" variable_id not found in SET statement";
            throw(SyntaxError(err.str()));
        }
        ++start;
        if(inputTokens.at(start).tag == Token::LP){
            ++start;
            tempStop = parenthesisCloseAt(inputTokens,start);
        }
        else{
            tempStop = start;
        }
        statement->setValue(BuildNumExpr(inputTokens,start,tempStop));
        start = tempStop;
        ++start;
        if(start!=expectedStop){
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start).row<<" missing right parenthesis ) to close SET statement";
            throw(SyntaxError(err.str()));
        }


    }
    else if(inputTokens.at(start).tag == Token::IF){
        If* statement = new If();
        node->addStatement(statement);
        //costruisco la bool_expression
        ++start;
        if(inputTokens.at(start).tag == Token::LP){
            ++start;
            tempStop = parenthesisCloseAt(inputTokens,start);

        }
        else{
            tempStop = start;
        }
        statement->setCondition(BuildBoolExpr(inputTokens,start,tempStop));
        start = tempStop+1;
        //costruzione blocco 1
        tempStop = parenthesisCloseAt(inputTokens,start);
        statement->setBlock1(parse(inputTokens,start,tempStop));
        start = tempStop+1;
        //costruzione blocco 2
        tempStop = parenthesisCloseAt(inputTokens,start);
        statement->setBlock2(parse(inputTokens,start,tempStop));
        start = tempStop;
        ++start;
        if(start!=expectedStop){
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start).row<<" missing right parenthesis ) to close IF statement";
            throw(SyntaxError(err.str()));
        }

    }
    else if(inputTokens.at(start).tag == Token::WHILE){
        While* statement = new While();
        node->addStatement(statement);
        ++start;
        if(inputTokens.at(start).tag == Token::LP){
            ++start;
            tempStop = parenthesisCloseAt(inputTokens,start);
        }
        else{
            tempStop = start;
        }
        statement->setCondition(BuildBoolExpr(inputTokens,start,tempStop));
        start = tempStop+1;
        //costruzione blocco
        tempStop = parenthesisCloseAt(inputTokens,start);
        statement->setBlock(parse(inputTokens,start,tempStop));
        start = tempStop;
        ++start;
        if(start!=expectedStop){
            std::stringstream err;
            err<<"Error on line: "<<inputTokens.at(start).row<<" missing right parenthesis ) to close WHILE statement";
            throw(SyntaxError(err.str()));
        }
    }
    else{
        std::stringstream err;
        err<<"Error on line: "<<inputTokens.at(start).row<<" statement keyword not found";
        throw(SyntaxError(err.str()));
    }
    return start;

}










Block* Parser::parse(std::vector<Token>& inputTokens, int start, int stop){ //start è il primo dello statement_block, quindi una LP, stop è l'ultimo quindi una RP
//questa funzione va a parsare quello che per la grammatica è stmt_block, vale a dire che può essere un (BLOCK statement_list) oppure solo uno statement
// Nel caso in cui non ci fosse la keyword BLOCK e ci fossero più statement verrà chiamato un errore
    Block* root = new Block();
    int localStop;
    
    if(inputTokens.at(stop).tag != Token::RP){
        std::stringstream err;
        err<<"Error on line: "<<inputTokens.at(start).row<<" missing right parenthesis )";
        throw(SyntaxError(err.str()));
    }

    else if(inputTokens.at(start).tag == Token::LP){
        ++start;
        if(inputTokens.at(start).tag == Token::BLOCK && inputTokens.at(start+1).tag == Token::LP){
            localStop = recursiveParsing(inputTokens,start+2,root);
            while(localStop<stop-1){
                if(inputTokens.at(localStop+1).tag == Token::LP){
                    localStop+=2;
                    localStop = recursiveParsing(inputTokens,localStop,root);
                }
                else{
                    std::stringstream err;
                    err<<"Error on line: "<<inputTokens.at(start).row<<" missing left parenthesis (";
                    throw(SyntaxError(err.str()));
                }
            }
            if(localStop!=stop-1){
                std::stringstream err;
                err<<"Error on line: "<<inputTokens.at(start).row<<" missing right parenthesis )";
                throw(SyntaxError(err.str()));
            }
        }   
        else{
            localStop = recursiveParsing(inputTokens,start,root);
            if(localStop!=stop){
                std::stringstream err;
                err<<"Error on line: "<<inputTokens.at(start).row<<" missing right parenthesis )";
                throw(SyntaxError(err.str()));
            }
        }
        
    }
    else{
        std::stringstream err;
        err<<"Error on line: "<<inputTokens.at(start).row<<" missing left parenthesis (";
        throw(SyntaxError(err.str()));

    }
    return root;


}