#include <string>
#include <iostream>
#include "Donut.h"
using namespace std;
Donut::Donut(int** input, int row, int col)
{
  this->grid = input;
  this->length = row;
  this->width = col;
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
void Donut::generation()
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
bool Donut::stabilized()
{
  return false;
}
void Donut::display()
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
string Donut::displayString()
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
