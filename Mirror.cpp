#include <string>
#include <iostream>
#include "Mirror.h"
using namespace std;
Mirror::Mirror(int** input, int row, int col) :  Mode(input, row, col)
{
  this->grid = input;
  this->length = row;
  this->width = col;
}
Mirror::~Mirror()
{
  for(int i = 0; i < length; i++)
  {
    for(int j = 0; j < width; j++)
    {
      delete[] grid[i];
      delete[] temp[i];
    }
  }
  delete[] grid;
  delete[] temp;
}
int Mirror::neighbors(int row, int col)
{
  int count = 0;
  for(int i = row-1; i <= row+1; i++)                                           //loop through three bordering rows
    for(int j = col-1; j <= col+1; j++)                                         //loop through three bordering cols
    {
      if(i >= 0 && i < this->length && j >= 0 && j < this->width)               //check bounds
         count += this->grid[i][j];                                             //since grid vals are 0 and 1, if we sum all the vals, we get neighbors
      else if(i < 0 && j < 0)                                                   //top left corner
        count += this->grid[row][col];                                          //corner cases will always mirror the center value (row,col)
      else if(i < 0 && j >= this->width)                                        //top right corner
        count += this->grid[row][col];
      else if(i >= this->length && j < 0)                                       //bottom left corner
        count += this->grid[row][col];
      else if(i >= this->length && j >= this->width)                            //bottom right corner
        count += this->grid[row][col];
      else if(i < 0)                                                            //top row
        count += this->grid[i+1][j];
      else if(j < 0)                                                            //left col
        count += this->grid[i][j+1];
      else if(i >= this->length)                                                //bottom row
        count += this->grid[i-1][j];
      else if(j >= this->width)                                                 //right col
        count += this->grid[i][j-1];
    }
  return count - this->grid[row][col];                                          //subtract itself, since we dont want to count that value
}
