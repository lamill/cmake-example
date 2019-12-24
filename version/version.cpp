#include "version.h"
#include <fstream>
#include <string>
std::string getVer(){
    std::ifstream file("/proc/version");
    std::string vers((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());
    file.close();
    return vers;
}