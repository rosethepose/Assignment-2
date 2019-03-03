#include <string>
using namespace std;
class Mirror
{
  public:
    Mirror(int** input, int row, int col);
    void generation();
    int neighbors(int row, int col);
    bool stabilized();
    void display();
  private:
    int** grid;
    int** temp;
    int length, width;
};
