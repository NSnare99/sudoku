
#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED
#endif // GRID_H_INCLUDED


class Grid
{
private:


public:
   void changeGridValue(int** grid, const int x, const int y, const int newVal);
   void populateGameGrid(int** grid, int option);
   bool checkValidEntry(int** grid, int x, int y, int newVal);
   bool isValidSolution(int** grid);
   bool areAllCellsFilled(int**);


};




