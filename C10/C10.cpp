#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Building{
    int x, y, id;
};
bool cmp(const Building &u, const Building &v)
{
    return u.x < v.x;
}
bool cmp2(const Building &u, const Building &v)
{
    return u.y < v.y;
}
int dist(Building &b1, Building &b2)
{
    return (b1.x - b2.x)*(b1.x-b2.x) + (b1.y-b2.y)*(b1.y-b2.y);
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
    sort(b.begin(), b.end(), cmp);
    vector<Building> candidate = {b[0]};
    for(int i = 1; i < n; i++)
    {
        Building now = b[i];
        for(auto it = candidate.begin(); it != candidate.end(); )
        {
            auto p = *it;
            int x = now.x - p.x;
            if(x*x > 25)
                it = candidate.erase(it);
            else
            {
                int d = dist(now, p);
                if(d < 25)
                {
                    edge[edge_s] = make_pair(now.id, p.id);
                    edge_s++;
                }
            }
            it++;
        }
        candidate.push_back(now);
    }
    
    return 0;
}