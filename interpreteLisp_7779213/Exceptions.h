#if !defined(EXCEPTIONS_H)
#define    EXCEPTIONS_H
#include <stdexcept>
#include <string>

struct SyntaxError : std::runtime_error{
    SyntaxError(std::string msg) : std::runtime_error(msg.c_str()) {};
};
struct VariableNotFound : std::runtime_error{
    VariableNotFound(std::string msg) : std::runtime_error(msg.c_str()) {};
};
struct InvalidInputValue : std::runtime_error{
    InvalidInputValue(std::string msg) : std::runtime_error(msg.c_str()) {};
};
struct DivisionByZero : std::runtime_error{
    DivisionByZero(std::string msg) : std::runtime_error(msg.c_str()) {};
};
struct InvalidOperatorAsParameter : std::runtime_error{
    InvalidOperatorAsParameter(std::string msg): std::runtime_error(msg.c_str()) {};
};

#endif