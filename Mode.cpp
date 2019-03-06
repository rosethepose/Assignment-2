#include <string>
#include <iostream>
#include <stdlib.h>
#include "Mode.h"
using namespace std;

Mode:: Mode(int** input, int row, int col){}

void Mode::generation()
{
  this->temp = new int*[this->length];
  for(int i = 0; i < this->length; ++i)
  {
    this->temp[i] = new int[this->width];
    for(int j = 0; j < this->width; ++j)
    {
      //A location that has one or fewer neighbors will be empty in the next generation.
      //If a cell was in that location, it dies of loneliness.
      //A location with two neighbors remains stable.  If there was a cell, there’s still a cell.
      //If it was empty, it’s still empty.
      //A location with three neighbors will contain a cell in the next generation.
      //If it currently has a cell, the cell lives on.  If it’s empty, a new cell is born.
      //A location with four or more neighbors will be empty in the next generation due to overcrowding.
      int n = neighbors(i,j);
      if(n <= 1)
        this->temp[i][j] = 0;
      //do nothing if == 2
      else if(n == 3)
        this->temp[i][j] = 1;
      else if(n <= 4)
        this->temp[i][j] = 0;
    }
  }
  //check if equal for stabliization
  stable = stabilized(grid, temp);
  for(int i = 0; i < this->length; ++i)
    for(int j = 0; j < this->width; ++j)
      this->grid[i][j] = this->temp[i][j];
}
bool Mode::stabilized(int** prev, int** next)
{
  for(int i = 0; i < this->length; ++i)
    for(int j = 0; j < this->width; ++j)
    {
       if(prev[i][j] != next[i][j])
        return false;
    }
  return true;
}
bool Mode::isStable()
{
  return stable;
}
void Mode::display()
{
  for(int i = 0; i < this->length; i++)
  {
    for(int j = 0; j < this->width; j++)
    {
      if(this->grid[i][j])
        cout << "X ";
      else
        cout << "- ";
    }
    cout << endl;
  }
  cout << endl;
}
string Mode::displayString()
{
  string out = "";
  for(int i = 0; i < this->length; i++)
  {
    for(int j = 0; j < this->width; j++)
    {
      if(this->grid[i][j])
        out += "X ";
      else
        out += "- ";
    }
    out += "\n";
  }
  out += "\n";
  return out;
}
