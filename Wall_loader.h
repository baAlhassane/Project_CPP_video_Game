//
// Created by DVEEC on 25/12/2021.
//

#ifndef CPP2022_WALL_LOADER_H
#define CPP2022_WALL_LOADER_H

#include <vector>
#include <string>
#include <cctype>
#include <map>
#include "Environnement.h"


struct Maze_wall{
    int row_;
    int col_;
    std::vector<std::string> data_;
    explicit Maze_wall(const std::vector<std::string> & maze);

    bool is_accessible(int i,int j) const;
    bool is_plus(int i,int j) const;
    bool is_next_plus_on_row(int i, int j) const;
    bool is_next_space_on_row(int i,int j) const;
    bool is_next_space_on_col(int i,int j) const;
    bool is_next_plus_on_col(int i, int j) const;
    bool contains_plus_after_on_row(int i,int j) const;
    bool contains_plus_after_on_col(int i,int j) const;

    bool is_letter_lowerCase(int i,int j) const;
    bool is_letter_upperCase(int i,int j) const;
    bool is_box(int i,int j) const;


    std::vector<Wall>  stock_wall_pictures() const ;
    //std::vector<Wall> stock_wall_gardiens() const;
    std::vector<std::pair<int,int>>  stock_wall_gardiens() const;
    std::vector<Box> stock_wall_boxes() const;





    Wall get_position_of_first_plus_after_on_row(int i,int j) const;
    [[nodiscard]] Wall get_position_of_first_plus_after_on_col(int i,int j) const;
    std::vector<Wall> get_coords_of_walls() const;

    // int get_texture_letter( char* img) const;


    void print_coords_of_wall() const;




    std::pair<Wall*,int> convert_to_array() const;// converti un tableay dynamique en pointeurs



};

#endif //CPP2022_WALL_LOADER_H
