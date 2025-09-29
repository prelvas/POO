#include <string>
#include <iostream>
#include <sstream>

int main_e3(){
    std::string fullname, part;

    std::cout << "Introduza o nome completo:";
    getline(std::cin, fullname);
    transform(fullname.begin(), fullname.end(), fullname.begin(), ::toupper);

    std::istringstream bufferi(fullname);

    while(bufferi >> part) {
        std::cout << part << std::endl;
        if (part == "FERNANDO")
            std::cout << "\tconheço-o!!!\n";
    }

    return 0;
}