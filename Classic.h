#ifndef MODE_H
#define MODE_H
#include <string>
#include "Mode.h"
using namespace std;
class Classic : public Mode
{
  public:
    Classic(int** input, int row, int col);
    ~Classic();
    int neighbors(int row, int col);
  private:
    int** grid;
    int** temp;
    int length, width;
};
#endif
