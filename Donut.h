#ifndef MODE_H
#define MODE_H
#include <string>
#include "Mode.h"
using namespace std;
class Donut : public Mode
{
  public:
    Donut(int** input, int row, int col);
    ~Donut();
    int neighbors(int row, int col);
    int mod(int n, int m);
  private:
    int** grid;
    int** temp;
    int length, width;
};
#endif
