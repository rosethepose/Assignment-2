#include <string>
#include <iostream>
#include "Classic.h"
using namespace std;
Classic::Classic(int** input, int row, int col) :  Mode(input, row, col)
{
  this->grid = input;
  this->length = row;
  this->width = col;
}
Classic::~Classic()
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
int Classic::neighbors(int row, int col)
{
  int count = 0;
  for(int i = row-1; i <= row+1; i++)                                      //loop through three bordering rows
    for(int j = col-1; j <= col+1; j++)                                    //loop through three bordering cols
      if(i >= 0 && i < this->length && j >= 0 && j < this->width)          //check bounds
         count += this->grid[i][j];                                        //since grid vals are 0 and 1, if we sum all the vals, we get neighbors
  return count - this->grid[row][col];                                     //subtract itself, since we dont want to count that value
}
