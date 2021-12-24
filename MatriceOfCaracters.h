//
// Created by DVEEC on 22/12/2021.
//

#ifndef READFILECPP_MATRICEOFCARACTERS_H
#define READFILECPP_MATRICEOFCARACTERS_H
#include <vector>
#include "ReadFile.h"
#include <string>

class MatriceOfCaracters {
private:
     std::size_t nbColumns;
    std::vector<std::vector<char>> matriceofcaracters;//stock only the caracters that compose the labyrinthe;
public:
    MatriceOfCaracters( const ReadFile &);
    ~MatriceOfCaracters();
    std::vector<std::vector<char>> getMatriceofcaracters() const;
    std::size_t  getNbColumns() const ;


};


#endif //READFILECPP_MATRICEOFCARACTERS_H
