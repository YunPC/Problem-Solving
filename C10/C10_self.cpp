#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int root[50000];
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
int main()
{
    int n, x, y, edge_s = 0;
    cin >> n;
    vector<Building> b(n);
    pair<int, int> edge[n];
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        b[i].x = x;
        b[i].y = y;
        b[i].id = i;
    }
    //line sweeping
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
        auto lower_point = Building(0, now.y - 5, -1);
        auto upper_point = Building(600000, now.y+5, -2);
        auto lower = candidate.lower_bound(lower_point);
        auto upper = candidate.upper_bound(upper_point);
        for(auto it = lower; it != upper; it++)
        {
            Building comp = *it;
            int d = dist(now, comp);
            if(d < 25)
                edge[edge_s++] = make_pair(now.id, it->id);
        }
        candidate.insert(now);
    }
    //initialize root and diff
    for(int i = 0; i < n; i++)
    {
        root[i] = i;
        ::size[i] = 1;
        ::rank[i] = 0;
    }
    

    return 0;
}