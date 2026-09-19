#include <iostream>
#include <fstream>
#include "analisiLessicale/Tokenizer.h"
#include "Parser.h"
#include "Context.h"
int main(int argc, char* argv[]){

    if(argc<2){
        std::cerr<<"Input file missing"<<std::endl;
        std::cerr<<"Input:"<<std::endl;
        std::cerr<<argv[0]<<"<filename>"<<std::endl;
        return EXIT_FAILURE;
    }
    std::ifstream inputFile;
    
	//apertura file
    try {
		inputFile.open(argv[1]);
	}
	catch (std::exception& e) {
		// Qualunque eccezione finisce qui
		std::cerr << "Cannot open " << argv[1] << " got: " << std::endl;
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	//tokenizzazione
    Tokenizer tokenize;
    std::vector<Token>inputTokens;

    try {
		// move è più efficiente che copiare l'intero stream di token
		inputTokens = std::move(tokenize(inputFile));
	}
	catch (LexicalError& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (std::exception& e) {
		std::cerr << "Cannot read from " << argv[1] << " got: " << std::endl;
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}


    
	//analisi sintattica
	Block* root = nullptr;
	Context c;
	try {
		
		Parser* parser = new Parser() ;
		root = parser->parse(inputTokens,0,inputTokens.size()-1);
		delete parser;
	}
	catch (SyntaxError& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	
	
	try{
		root->interpret(c);
	}
	catch(SyntaxError& e){
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch(VariableNotFound& e){
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch(InvalidInputValue& e){
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch(DivisionByZero& e){
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch(InvalidOperatorAsParameter& e){
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	catch(std::exception& e){
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;

	delete root;


}