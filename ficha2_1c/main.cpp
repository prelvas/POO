#include <iostream>
#include <string>
#include "libraries/DataStore.h"
#include "libraries/UserInterface.h"

int main() {
    std::string pal;
    std::cout << "Introduza uma palavra para chamar as duas funções:";
    std::cin >> pal;
    //i)
    std::cout << "Resultado da 1ª função:" << (DataStore::dadosSaoValidos(pal)?"válida":"inválida") << std::endl;
    std::cout << "Resultado da 2ª função:" << (UserInterface::dadosSaoValidos(pal)?"válida":"inválida") << std::endl;

    //ii)
    /*
    {
        using DataStore::dadosSaoValidos;
        std::cout << "Resultado da 1ªfunção:" << (dadosSaoValidos(pal) ? "válida" : "inválida") << std::endl;
    }
    {
        using UserInterface::dadosSaoValidos;
        std::cout << "Resultado da 2ª função:" << (dadosSaoValidos(pal) ? "válida" : "inválida") << std::endl;
    }*/
    //iii)
    /*
     using namespace DataStore;
     std::cout << "Resultado da 1ª função:" << (dadosSaoValidos(pal)?"válida":"inválida") << std::endl;
     std::cout << "Resultado da 2ª função:" << (UserInterface::dadosSaoValidos(pal)?"válida":"inválida") << std::endl;
    */
    //iv)
    /*
     using namespace  DataStore;
     using namespace  UserInterface;
     std::cout << "Resultado da 1ª função:" << (DataStore::dadosSaoValidos(pal)?"válida":"inválida") << std::endl;
     std::cout << "Resultado da 2ª função:" << (UserInterface::dadosSaoValidos(pal)?"válida":"inváálida") << std::endl;
    */
    return 0;
}

