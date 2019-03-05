#include <string>
using namespace std;
class Donut
{
  public:
    Donut(int** input, int row, int col);
    void generation();
    int neighbors(int row, int col);
    bool stabilized();
    void display();
    int mod(int n, int m);
    string displayString();
  private:
    int** grid;
    int** temp;
    int length, width;
};
