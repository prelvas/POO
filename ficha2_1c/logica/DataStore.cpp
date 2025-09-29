//
// Created by Paulo Relvas on 19/09/2025.
//

#include "../libraries/DataStore.h"

namespace DataStore{
    bool dadosSaoValidos(std::string input){
        if(input.length() >= 5 && input.length() <= 10)
            return true;
        return false;
    }
}