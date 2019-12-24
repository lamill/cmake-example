#include "upper.h"
#include <string>
#include <algorithm>

std::string toUpper(std::string_view str){
    std::string retVal(str); 
    std::transform(retVal.begin(),
                    retVal.end(),
                    retVal.begin(),
                    [](auto a){return std::toupper(a);});
    return retVal;
}
