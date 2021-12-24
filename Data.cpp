//
// Created by DVEEC on 24/12/2021.
//

#include "Data.h"
#include "MatriceOfCaracters.h"
#include <istream>



Data::Data():height(0),width(0) {
    data= nullptr;

}
Data::Data(const MatriceOfCaracters &matriceOfCaracters) {
       auto d=matriceOfCaracters.getMatriceofcaracters();// it' std::vector<std::vector<char> type
    height=matriceOfCaracters.getMatriceofcaracters().size();
    width=matriceOfCaracters.getNbColumns();
    data=new char *[height];
    for (int i = 0; i <height ; ++i) {
        data[i]=new char [width];
    }

    for (int i = 0; i <height ; ++i) {

        for (int j = 0; j <width ; ++j) {

            data[i][j]=d[i][j];
            
        }
        
    }

}

Data::~Data(){

    if(data != nullptr){
        for (int i = 0; i < height; ++i) {
            delete [] data[i];
            
        }

        delete []data;


    }


}


Data::Data(const Data &copy) {
    if(copy.data!= nullptr)  {
        for (int i = 0; i < copy.height; ++i) {
            for (int j = 0; j <copy.width ; ++j) {

                data[i][j]=copy.data[i][j];

            }
        }

    }
}


const Data &Data::operator=(const Data &data1) {
    delete data;

    if(data1.data!= nullptr)  {
        for (int i = 0; i < data1.height; ++i) {
            for (int j = 0; j <data1.width ; ++j) {

                data[i][j]=data1.data[i][j];

            }
        }

    }


    return *this;
}

