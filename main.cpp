#include <iostream>
#include "upper.h"
#include "version.h"
int main(int argc, char const *argv[])
{   
   std::string ver = getVer();
   std::cout<<toUpper(ver)<<std::endl;
   
    return 0;
}

