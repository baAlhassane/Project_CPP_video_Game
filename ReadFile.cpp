//
// Created by DVEEC on 23/12/2021.
//

//
// Created by DVEEC on 22/12/2021.
//

#include "ReadFile.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


ReadFile::ReadFile(const std::string & filename) {

    /// On ouvre le fichier
    std::ifstream f2;
    f2.open("labyrinthe.txt",std::ios_base::in);
    //f2.open(filename,std::ios_base::in);
    /// on cree le vecteur qui contient les lignes
    //std::vector<std::string> lines;
   // std::string line;

    if(f2.is_open()){
        while (f2.good()){


            getline(f2,line);
            char letter;
            std::string im;
            std::stringstream ss;
            ss.str("");
            ss<<line;
            //ss<<line;c_str()
            ss>>letter>>im;
            if(std::islower(static_cast<unsigned char>(letter)) &&( std::isalpha(static_cast<unsigned char>(letter)))  &&(( std::isalpha(static_cast<unsigned char>(line[0]))))  ){


                if(!(map_textures[letter])) {
                    char *cstr = &im[0];
                    //  char* cstr;
                    //strcpy(cstr, im.c_str());
                   // map_textures[letter]=Environnement::wall_texture(cstr);
                    std::cout<<"map_textures["<<letter<<"]   =  " <<map_textures[letter]<< "   // image corespondant est "<<cstr <<std::endl;
                }
            }

            else {
                if(line.length()!=0 && line[0]!='#')
                    lines.push_back(line);  /// On copie dans le vecteur

            }
        }
        f2.close();       /// fermeture du fichier

    }

 /*
    for (int i = 0; i <lines.size();i++){
   std::cout<<lines[i]<<std::endl;
 }
  */


 nbLines=lines.size();


    std::size_t maxColumns=0;
    for (int i = 0; i < lines.size(); ++i) {
        // std::cout<<lines.size()<<std::endl;
        // std::cout<<lines[i]<<std::endl;
        if(maxColumns<lines[i].length()){
            maxColumns=lines[i].length();
        }

        //if(lines[i][0]=="+" || lines[i][0]=="-"|| lines[i][0]=="|")

    }

    nbColumns=maxColumns;

}

ReadFile::~ReadFile() {}




std::vector<std::string> ReadFile::getLines() const{

    return lines;
}



std::size_t ReadFile::getNbLines() const {
    return nbLines;
}


std::size_t ReadFile::getNbColumns() const   {
    return nbColumns;
}



