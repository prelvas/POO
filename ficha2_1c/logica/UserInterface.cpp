//
// Created by Paulo Relvas on 19/09/2025.
//
#include "../libraries/UserInterface.h"

namespace UserInterface{
    bool dadosSaoValidos(std::string input){
        if(input.at(0) >= 'A' && input.at(0) <= 'Z' )
            return true;
        return false;
    }
}