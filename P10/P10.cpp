#include <iostream>

using namespace std;

const int N = 451;

int cell[N], n, res;
int patri[N][N];
int weight[N];
int d[N];
bool keep = false;

bool isCluster(int b)
{
  for(int i = 1; i < b; i++)
  {
    for(int j = i+1; j < b; j++)
    {
      if(patri[cell[i]][cell[j]] == 0)
        return false;
    }
  }
  return true;
}

void getMaxWeight(int n)
{
  int sum = 0;
  for(int i = 0; i < n; i++)
    sum += weight[cell[i]];
  res = max(res, sum);
  keep = true;
}

void findCluster(int i, int l, int s)
{
  for(int j = i+1; j <= n - (s-l); j++)
  {
    if(d[j] >= s-1)
    {
      cell[l] = j;

      if(isCluster(l+1))
      {
        if(l < s)
          findCluster(j, l+1, s);
        else
          getMaxWeight(l+1);
      }
    }
  }
}

int main()
{
  int b, w, p1, p2, k = 2;
  cin >> n >> b;
  for(int i = 1; i <= n; i++)
  {
    cin >> w;
    weight[i] = w;
  }
  for(int i = 0; i < b; i++)
  {
    cin >> p1 >> p2;
    patri[p1][p2] = 1;
    patri[p2][p1] = 1;
    ++d[p1];
    ++d[p2];
  }
  res = 0;
  keep = true;
  while(keep)
  {
    keep = false;
    findCluster(0, 1, k);
    k++;
  }

  cout << res << endl;
  
}
