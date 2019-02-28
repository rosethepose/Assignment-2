#include <string>
#include <iostream>
#include "Mode.h"
using namespace std;
Classic::Classic(int** input, int row, int col)
{
  grid = input;
  length = row;
  width = col;
}
void Classic::generation()
{
  temp = new int*[length];
  for(int i = 0; i < length; ++i)
  {
    temp[i] = new int[width];
    for(int j = 0; j < width; ++j)
    {
      //A location that has one or fewer neighbors will be empty in the next generation.
      //If a cell was in that location, it dies of loneliness.
      //A location with two neighbors remains stable.  If there was a cell, there’s still a cell.
      //If it was empty, it’s still empty.
      //A location with three neighbors will contain a cell in the next generation.
      //If it currently has a cell, the cell lives on.  If it’s empty, a new cell is born.
      //A location with four or more neighbors will be empty in the next generation due to overcrowding.
      int n = neighbors(i,j);
      cout << n;
      if(n <= 1)
        temp[i][j] = 0;
      //do nothing if == 2
      else if(n == 3)
        temp[i][j] = 1;
      else if(n <= 4)
        temp[i][j] = 0;
    }
    cout << endl;
  }
  for(int i = 0; i < length; ++i)
    for(int j = 0; j < width; ++j)
      grid[i][j] = temp[i][j];
}
int Classic::neighbors(int row, int col)
{
  int count = 0;
  for(int i = row-1; i <= row+1; i++)
    for(int j = col-1; j <= col+1; j++)
      if(i >= 0 && i < length && j >= 0 && j < width)
         count += grid[i][j];
  return count - grid[row][col];
}
string Classic::mode()
{
  return "Classic";
}
bool Classic::stabilized()
{
  return false;
}
void Classic::display()
{
  for(int i = 0; i < length; i++)
  {
    for(int j = 0; j < width; j++)
      cout << grid[i][j] << " ";
    cout << endl;
  }
}
