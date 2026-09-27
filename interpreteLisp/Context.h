#if !defined(CONTEXT_H)
#define CONTEXT_H
#include <unordered_map>
#include <string>
#include <sstream>
#include "Exceptions.h"
class Context{
public:
    Context() = default;
    Context(Context const& c) = delete;
    ~Context() = default;
    Context& operator=(const Context& other) = delete;

    int64_t getNumValue(std::string key)const {
        auto iter = numMap.find(key);
        if(iter!=numMap.end()){
            return (*numMap.find(key)).second;
        }
        else{
            std::stringstream err;
            err<<"Variable "<<key<<" not found";
            throw(VariableNotFound(err.str()));
        }
    }
    

    void setNumValue(std::string key, int64_t value){
        auto iter = numMap.find(key);
        if(iter!= numMap.end()){
            numMap[key] = value;
        }
        else{
            numMap.insert({key,value});
        }

    }
    
    
private:
    std::unordered_map<std::string,int64_t>numMap;

};

#endif