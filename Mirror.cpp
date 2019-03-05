#include <string>
#include <iostream>
#include "Mirror.h"
using namespace std;
Mirror::Mirror(int** input, int row, int col)
{
  this->grid = input;
  this->length = row;
  this->width = col;
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
void Mirror::generation()
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
      //cout << n;
      if(n <= 1)
        this->temp[i][j] = 0;
      //do nothing if == 2
      else if(n == 3)
        this->temp[i][j] = 1;
      else if(n <= 4)
        this->temp[i][j] = 0;
    }
    //cout << endl;
  }
  for(int i = 0; i < this->length; ++i)
    for(int j = 0; j < this->width; ++j)
      this->grid[i][j] = this->temp[i][j];
}
bool Mirror::stabilized()
{
  return false;
}
void Mirror::display()
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
string Mirror::displayString()
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
