#include <iostream>
using namespace std;
class Mode
{
public:
  Mode(int** input, int row, int col);
  void generation();
  virtual int neighbors(int row, int col);
  bool stabilized(int** prev, int** next);
  void display();
  string displayString();
  bool isStable();
protected:
  int** grid;
  int** temp;
  int** next;
  int** prev;
  int length, width;
  bool stable = false;
};
