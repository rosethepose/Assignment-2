#ifndef MODE_H
#define MODE_H
#include <string>
#include "Mode.h"
using namespace std;
class Mirror : public Mode
{
  public:
    Mirror(int** input, int row, int col);
    ~Mirror();
    int neighbors(int row, int col);
  private:
    int** grid;
    int** temp;
    int length, width;
};
#endif
