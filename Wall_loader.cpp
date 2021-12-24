//
// Created by DVEEC on 24/12/2021.
//

#include <iostream>
#include "Wall_loader.h"





Maze_wall::Maze_wall(const std::vector<std::string> &maze) {
    if (maze.empty())
        throw std::invalid_argument("labyrinthe VIDE !!!.");

    row_=maze.size();
    col_=maze[0].length();
    data_=maze;

}


bool Maze_wall::is_accessible(int i, int j) const {
    return 0<=i && i<row_ && 0<=j && j<col_ ;
}

bool Maze_wall::is_plus(int i, int j) const {
    return is_accessible(i,j) && data_[i][j]=='+' ;
}

bool Maze_wall::is_next_plus_on_row(int i, int j) const {
    return is_plus(i,j+1);
}

bool Maze_wall::is_next_plus_on_col(int i, int j) const {
    return is_plus(i+1,j);
}

bool Maze_wall::contains_plus_after_on_row(int i, int j) const {
    for (int k = j+2; k < col_; ++k) {
        if (is_plus(i,k))
            return true;
    }
    return false;
}

bool Maze_wall::contains_plus_after_on_col(int i, int j) const {
    for (int k = i+2; k <row_ ; ++k) {
        if (is_plus(k,j))
            return true;
    }
    return false;
}

Wall Maze_wall::get_position_of_first_plus_after_on_row(int i, int j) const {
    for (int k = j+2; k < col_; ++k) {
        if (is_plus(i,k))
            return {i,j,i,k,0};
    }
    return {-1,-1,-1,-1,0};
}

Wall Maze_wall::get_position_of_first_plus_after_on_col(int i, int j) const {
    for (int k = i+2; k < row_; ++k) {
        if (is_plus(k,j))
            return {i,j,k,j,0};
    }
    return {-1,-1,-1,-1,0};
}

std::vector<Wall> Maze_wall::get_coords_of_walls() const {
    std::vector<Wall> res;
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < col_; ++j) {
            if (is_plus(i,j) && !is_next_plus_on_row(i,j) &&
                contains_plus_after_on_row(i,j) && !is_next_space_on_row(i,j)){
                Wall wall_on_row=get_position_of_first_plus_after_on_row(i,j);
                res.push_back(wall_on_row);
            }
            if (is_plus(i,j) && !is_next_plus_on_col(i,j) &&
                contains_plus_after_on_col(i,j) && !is_next_space_on_col(i,j)){
                Wall wall_on_col=get_position_of_first_plus_after_on_col(i,j);
                res.push_back(wall_on_col);
            }
        }
    }
    return res;
}

void Maze_wall::print_coords_of_wall() const {
    auto walls=get_coords_of_walls();

    for (const auto &wall : walls) {
        std::cout<< wall._x1<<","<<wall._y1<<"    "<<wall._x2<<","<<wall._y2 <<std::endl;

    }

}

bool Maze_wall::is_next_space_on_row(int i, int j) const {
    return is_accessible(i,j+1) && data_[i][j+1]==' ';
}

bool Maze_wall::is_next_space_on_col(int i, int j) const {
    return is_accessible(i+1,j) && data_[i+1][j]==' ';
}

std::pair<Wall *,int> Maze_wall::convert_to_array() const {
    auto cords=get_coords_of_walls();
    Wall *p=new Wall[cords.size()];
    for (int i = 0; i < cords.size() ; ++i) {
        p[i]=cords[i];
    }
    return {p,cords.size()};
}



bool Maze_wall::is_letter_lowerCase(int i,int j) const{
    return (is_accessible(i,j))&& (std::islower(static_cast<unsigned char>(data_[i][j]))) &&( std::isalpha(static_cast<unsigned char>(data_[i][j])));
}


bool  Maze_wall::is_letter_upperCase(int i,int j) const{
    return (is_accessible(i,j))&& (std::isupper(static_cast<unsigned char>(data_[i][j]))) &&(  ( std::isalpha(static_cast<unsigned char>(data_[i][j]))));
}




bool  Maze_wall::is_box(int i,int j) const{

    return (is_accessible(i,j))&&is_letter_upperCase(i,j)&&( data_[i][j]=='X');
}


std::vector<Wall> Maze_wall::stock_wall_pictures() const  {
    std::vector<Wall> wall_pictures;
    for(int i=0;i<row_;i++){
        for(int j=0;j<col_;j++){
            if(is_letter_lowerCase(i,j) ) {

                if( ( is_accessible(i,j-1)) && (is_accessible(i,j+1 ) ) && ( is_accessible(i,j+2))   ) {
                    if ((data_[i][j - 1] == '-') && (data_[i][j + 1] == '-')) {
                        Wall m1{i, j, i, j+2, 0};
                        wall_pictures.push_back(m1);

                    }
                }

                if( ( is_accessible(i-1,j)) && (is_accessible(i+1,j ) ) && ( is_accessible(i+2,j))   ) {
                    if ((data_[i - 1][j] == '|') && (data_[i + 1][j] == '|')) {
                        Wall m2{i, j, i + 2, j, 0};
                        //Wall m2{i, j, i , j+2, 0};
                        wall_pictures.push_back(m2);
                    }
                }

            }
        }


    }
    return wall_pictures;
}




std::vector<std::pair<int,int>>  Maze_wall::stock_wall_gardiens() const{
    std::vector<std::pair<int,int>>wall_gardiens;
    for(int i=0;i<row_;i++){
        for(int j=0;j<col_;j++){
            if( ( (is_letter_upperCase(i,j))&& ( (data_[i][j]=='G')   )))
            { std::pair<int,int>g= std::make_pair(i,j);


                wall_gardiens.push_back(g);
            }

        }
    }

    return wall_gardiens;

}


std::vector<Box> Maze_wall::stock_wall_boxes() const{
    std::vector<Box> wall_box;
    for(int i=0;i<row_;i++){
        for(int j=0;j<col_;j++){
            if(is_box(i,j)){
                Box b{i,j,0};
                //Box b{i,j,0};
                wall_box.push_back(b);

            }
        }
    }
    return wall_box;
}



