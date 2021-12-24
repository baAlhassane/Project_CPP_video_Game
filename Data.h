//
// Created by DVEEC on 24/12/2021.
//

#ifndef CPP2022_DATA_H
#define CPP2022_DATA_H
#include "MatriceOfCaracters.h"

class Data {

private:
    int height;
    int width;
    char ** data ;
public:
    Data();
    Data(const MatriceOfCaracters& matrice);
    Data(const Data& copy);
    const Data & operator=(const Data & data1);
    ~Data();

};


#endif //CPP2022_DATA_H





