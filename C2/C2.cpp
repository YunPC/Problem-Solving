#include <iostream>

int cache[500][500];
int data[500][500];

using std::cout;
using std::cin;
using std::max;
using std::min;
using std::endl;

int findTrail(int row, int col, int size, int height);

int main() {

  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0 ; j <n ; j++)
      {
        cin >> data[i][j];
      }
  }
  int result = -1234;
  int left_height, right_height, up_height, down_height;
  int max_lr;
  int max_ud;
  int max_diff;

  for(int row = 0; row < n; row++)
  {
    for(int col = 0; col < n; col++)
    {
      left_height = findTrail(row, col-1, n, data[row][col]);
      right_height = findTrail(row, col+1, n, data[row][col]);
      up_height = findTrail(row-1, col, n, data[row][col]);
      down_height = findTrail(row+1, col, n, data[row][col]);
      max_lr = max(left_height, right_height);
      max_ud = max(up_height, down_height);
      max_diff = max(max_lr, max_ud);
      result = max(result, max_diff);
      if(result == 0)
        cache[row][col] = -1;
      cache[row][col] = max_diff;
    }
  }


  cout << result;

}

int findTrail(int row, int col, int n, int height)
{
  if(row > n-1 || row < 0 || col > n-1 || col < 0)
    return 0;
  else if(height <= data[row][col])
    return 0;
  else if(cache[row][col] == -1)
    return height - data[row][col];
  else if(cache[row][col] > 0)
    return height - data[row][col] + cache[row][col];
  else{
    int current_height = data[row][col];
    int left_height, right_height, up_height, down_height;
    int diff = height - data[row][col];
    int result;
    left_height = diff + findTrail(row, col-1, n, current_height);
    right_height = diff + findTrail(row, col+1, n, current_height);
    up_height = diff + findTrail(row-1, col, n, current_height);
    down_height = diff + findTrail(row+1, col, n, current_height);
    
    int max_lr = max(left_height, right_height);
    int max_ud = max(up_height, down_height);
    int max_height = max(max_lr, max_ud);

    return max_height;
    

  }
}