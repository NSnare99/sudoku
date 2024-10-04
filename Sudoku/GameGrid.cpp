#include "GameGrid.h"
#include <iostream>
#include <string>
#include <wx/wx.h>


int easyGrid[9][9] = {

    {0,2,5,0,0,3,9,0,7},
    {0,8,0,0,0,5,6,0,1},
    {0,1,0,0,9,8,2,5,0},
    {0,0,7,0,6,0,1,2,0},
    {8,0,2,1,0,7,5,0,9},
    {0,5,4,0,8,0,3,0,0},
    {0,7,6,8,5,0,0,1,0},
    {5,0,1,4,0,0,0,9,0},
    {9,0,8,3,0,0,7,6,0}

    };



int hardGrid[9][9] = {

    {4,0,0,1,0,0,6,7,0},
    {7,0,3,2,0,0,0,1,0},
    {0,0,0,0,0,0,5,0,0},
    {0,0,0,0,8,0,0,5,9},
    {0,0,7,0,4,0,8,0,0},
    {8,6,0,0,7,0,0,0,0},
    {0,0,6,0,0,0,0,0,0},
    {0,3,0,0,0,7,2,0,5},
    {0,8,5,0,0,9,0,0,7}

    };



bool Grid::isValidSolution(int** grid){
   for(int i = 0; i < 9; i++){
    for(int j = 0; j < 9; j++){
        if(!checkValidEntry(grid, i, j, grid[j][i])){
        return false;
        }
    }
   }
   return true;
}


bool Grid::checkValidEntry(int** grid, int x, int y, int newVal)
{

    //Always allow erasing of values
    if(newVal == 0){
        return true;
    }
    //Restrict illegal values
    if(newVal > 9 || newVal < 0){
    wxLogError("Invalid Selection");
    return false;
    }
    //Check column conflicts
    for(int x_coord = 0; x_coord < 9; x_coord++){
        if(x_coord != x && grid[y][x_coord] == newVal){

            wxLogError("Clashes with Value in Column");
            return false;
        }
    }
    //Check row conflicts
    for(int y_coord = 0; y_coord < 9; y_coord++){
        if(y_coord != y && grid[y_coord][x] == newVal){
        wxLogError("Clashes with Value in Row");
        return false;
        }
    }

    //Check sub-square conflicts
    int origin_x = x - (x % 3);
    int origin_y = y - (y % 3);

    for(int x_coord = origin_x; x_coord < origin_x + 3; x_coord++){
        for(int y_coord = origin_y; y_coord < origin_y + 3; y_coord++){
                if(y_coord != y && x_coord != x && grid[y_coord][x_coord] == newVal){
                        wxLogError("Clashes with Value in Sub-Square");
                        return false;
                }
        }
    }

    return true;



}

void Grid::populateGameGrid(int** grid, int option){



    if(option == 1){
       for(int outer = 0; outer < 9; outer++){
        for(int inner = 0; inner < 9; inner++){
            grid[outer][inner] = easyGrid[outer][inner];
        }
       }
    }
    else if(option == 2){
       for(int outer = 0; outer < 9; outer++){
        for(int inner = 0; inner < 9; inner++){
            grid[outer][inner] = hardGrid[outer][inner];
        }
       }
    }

    else{
        wxLogError("Invalid choice of grid");
    }

}


