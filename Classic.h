#include <string>
using namespace std;
class Classic
{
  public:
    Classic(int** input, int row, int col);
    void generation();
    int neighbors(int row, int col);
    string mode();
    bool stabilized();
    void display();
  private:
    int** grid;
    int** temp;
    int length, width;
};
