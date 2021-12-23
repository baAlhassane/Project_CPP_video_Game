//
// Created by DVEEC on 22/12/2021.
//

#include "MatriceOfCaracters.h"
#include <vector>
#include <string>
#include <iostream>

MatriceOfCaracters::MatriceOfCaracters(const ReadFile &readfile ) {

    for(auto &line:readfile.getLines()){
        std::vector<char> vector_char;
        for(auto car:line){
            vector_char.push_back(car);

        }

        matriceofcaracters.push_back(vector_char);



    }

}

MatriceOfCaracters::~MatriceOfCaracters() {}

std::vector<std::vector<char>> MatriceOfCaracters::getMatriceofcaracters() const {
    return matriceofcaracters;
}
