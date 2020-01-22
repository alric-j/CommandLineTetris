#include "exception.h"
#include <string>
using std::string;

string Exception::getErrorMessage(){
    return s;
}

Exception::Exception(std::string s) : s{s} {}
