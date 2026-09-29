#if !defined(LEXICAL_EXCEPTIONS_H)
#define LEXICAL_EXCEPTIONS_H
#include <stdexcept>
struct LexicalError : std::runtime_error{
    LexicalError(const char* msg) : std::runtime_error(msg) {};
	LexicalError(std::string msg) : std::runtime_error(msg.c_str()) {};
};

#endif
