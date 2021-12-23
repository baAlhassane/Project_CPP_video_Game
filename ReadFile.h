//
// Created by DVEEC on 22/12/2021.
//

#ifndef READFILECPP_READFILE_H
#define READFILECPP_READFILE_H

#include <iostream>
#include <vector>
#include <string>
#include <map>



class ReadFile {

private:
    std::string line; // one line of our file
    std::vector<std::string> lines; // All lines of our file
    std::map<char,int> map_textures;
    std::size_t nbLines;
    std::size_t nbColumns;

public:
    ReadFile(const std::string & filename="labyrinthe.txt");
    ~ReadFile();
    std::vector<std::string> getLines()const;//get all the lines like vector of string
    std::size_t getNbColumns() const;
    std::size_t getNbLines() const;


};


#endif //READFILECPP_READFILE_H
