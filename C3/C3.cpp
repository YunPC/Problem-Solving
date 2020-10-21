#include <iostream>
#include <vector>
#include <set>
#include <functional>

using namespace std;

const int INF = 2147483647;
typedef pair<int, int> pii;
struct City{
    int to;
    int distance = 1;
    City(int to){
        this ->to = to;
        this -> distance = 1;
    }
};


vector<int> dijkstra(vector<vector<City>>& v, int begin);

int main()
{
    int p, q, r, n, m;
    int first_city, second_city;
    cin >> p >> q >> r >> n >> m;
    vector<vector<City>> adj_cities;
    adj_cities.assign(n+1, vector<City>());
    for(int i = 0; i < m; i++)
    {
        cin >> first_city >> second_city;
        adj_cities[first_city].push_back(City(second_city));
        adj_cities[second_city].push_back(City(first_city));
    }

    vector<int> alpha_traverse = dijkstra(adj_cities, 1);
    vector<int> beta_traverse = dijkstra(adj_cities, 2);
    vector<int> destination_traverse = dijkstra(adj_cities, n);


    int cost = INF;
    int temp_cost = 0;
    for(int i = 1; i < n+1; i++)
    {
         temp_cost = p*alpha_traverse[i] + q*beta_traverse[i] + r*destination_traverse[i];
         cost = min(cost, temp_cost);
    }
    cout << cost;
    return 0;
}


vector<int> dijkstra(vector<vector<City>>& v, int begin) {
    vector<int> d;
    set<pii> pq;
    d.assign(v.size(), INF);
    d[begin] = 0;
    pq.insert(make_pair(0, begin));
    while (pq.empty() == false)
    {
        pii e = *pq.begin();
        pq.erase(e);
        for(int i = 0; i < v[e.second].size(); i++)
        {
            if (d[v[e.second][i].to] > d[e.second] + v[e.second][i].distance)
            {
                pq.erase(make_pair(d[v[e.second][i].to], v[e.second][i].to));
                d[v[e.second][i].to] = d[e.second] + v[e.second][i].distance;
                pq.insert(make_pair(d[v[e.second][i].to], v[e.second][i].to));
            }
        }
    }
    return d;

}