#include <string>
#include <iostream>
#include "Donut.h"
using namespace std;
Donut::Donut(int** input, int row, int col):  Mode(input, row, col)
{
  this->grid = input;
  this->length = row;
  this->width = col;
}
Donut::~Donut()
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
int Donut::mod(int n, int m)
{
  return (n+=m) % m; //so that mod works for negatives
}
int Donut::neighbors(int row, int col)
{
  int count = 0;
  for(int i = row-1; i <= row+1; i++)                                           //loop through rows that border index
    for(int j = col-1; j <= col+1; j++)                                         //loop through cols that border index
      count += this->grid[mod(i,this->length)][mod(j,this->width)];                               //mod by length gives our desired index
  return count - this->grid[row][col];                                                //subtract by itself, since the loop counts itself as a neighbor
}
