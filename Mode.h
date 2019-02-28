#include <iostream>
using namespace std;
class Mode
{
public:
  void generation();
  int neighbors(int row, int col);
  string mode();
  bool stabilized();
  void display();
protected:
  int** grid;
  int** temp;
  int length, width;
};
class Classic : protected Mode
{
  public:
    Classic(int** input, int row, int col);
};
