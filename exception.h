#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>

class Exception {
    std::string s;
public:
    Exception(std::string);
    std::string getErrorMessage();
};



#endif
