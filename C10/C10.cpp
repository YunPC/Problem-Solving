#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int root[50000];
int diff[50000];
int size[50000];
int rank[50000];

struct Building{
    int x, y, id;
    Building(){}
    Building(int x, int y, int id) : x(x), y(y), id(id){}
    bool operator < (const Building &v) const {
        if(y == v.y)
            return x < v.x;
        else
            return y < v.y;
        
    }
};
bool cmp(const Building &u, const Building &v)
{
    return u.x < v.x;
}
int dist(Building &b1, Building &b2)
{
    return (b1.x - b2.x)*(b1.x-b2.x) + (b1.y-b2.y)*(b1.y-b2.y);
}
int find(int u)
{
    if(u == root[u])
        return u;
    return root[u] = find(root[u]);
}
int merge(int u, int v)
{
    if(u == -1 || v == -1)
      return max(u, v);
    u = find(u);
    v = find(v);

    if(u == v)
      return u;

    if(::rank[u] > ::rank[v])
      swap(u, v);

    if(::rank[u] == ::rank[v])
      ::rank[v]++;
    
    root[u] = v;
    ::size[v] += ::size[u];
    return v;
}
int maxStore(int n)
{
  int result = 0;
  for(int i = 0; i < n; i++)
  {
    if(root[i] == i)
    {
      int temp = diff[i];
      if(temp > i)
        continue;
      
      int s = ::size[i];
      int d_s = temp == -1 ? 0 : ::size[temp];

      result += max(s, d_s);
    }
    
  }
  
  return result;
}
int main()
{
    int n, x, y, edge_s = 0;
    cin >> n;
    vector<Building> b(n);
    vector<pair<int, int>> edge;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        b[i].x = x;
        b[i].y = y;
        b[i].id = i;
    }
    
    sort(b.begin(), b.end(), cmp);
    set<Building> candidate = {b[0]};
    int start = 0;
    for(int i = 1; i < n; i++)
    {
        Building now = b[i];
        while (start < i)
        {
            auto p = b[start];
            int x = now.x - p.x;
            if(x*x > 25){
                candidate.erase(p);
                start += 1;
            }
            else
                break;
            
        }
        auto lower_point = Building(0, now.y - 6, -1);
        auto upper_point = Building(600000, now.y+6, -2);
        auto lower = candidate.lower_bound(lower_point);
        auto upper = candidate.upper_bound(upper_point);
        for(auto it = lower; it != upper; it++)
        {
            Building comp = *it;
            int d = dist(now, comp);
            if(d <= 25)
                edge.push_back(make_pair(now.id, it->id));
        }
        candidate.insert(now);
    }
    
    for(int i = 0; i < n; i++)
    {
        root[i] = i;
        diff[i] = -1;
        ::size[i] = 1;
        ::rank[i] = 0;
    }
    for(int i = 0; i < edge.size(); i++)
    {
        int u = find(edge[i].first);
        int v = find(edge[i].second);
        int a = merge(u, diff[v]);
        int b = merge(v, diff[u]);
        diff[a] = b;
        diff[b] = a;

    }
    
    int res = maxStore(n);
    cout << n-res;
    return 0;
}