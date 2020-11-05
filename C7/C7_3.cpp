#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <stack>

#define RED 1
#define BLUE 2
#define YELLOW 3
#define GREEN 4

using namespace std;

void makeGraph(vector<int> graph[], int u, int v, int visit[], map<int, int> &map)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
    visit[u] = RED;
    visit[v] = BLUE;
    map.insert(make_pair(u, u));
    map.insert(make_pair(v, u));
}

void dfs(vector<int> graph[], int u, int v, int visit[], map<int, int> &map, int n)
{
    stack<int> s;
    if (visit[u] == RED)
        visit[v] = GREEN;
    else
        visit[v] = YELLOW;
    int id = map.find(u)->second;
    s.push(v);
    while (!s.empty())
    {
        int now = s.top();
        map.find(now)->second = id;
        int color;
        s.pop();
        if (visit[now] == GREEN)
            color = YELLOW;
        else
            color = GREEN;

        for (int i = 0; i < graph[v].size(); i++)
        {
            int next = graph[v][i];
            if (visit[next] == 1 || visit[next] == 2)
            {
                visit[next] = color;
                s.push(now);
                s.push(next);
                map.find(next)->second = id;
                break;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (visit[i] == YELLOW)
            visit[i] = RED;
        else if (visit[i] == GREEN)
            visit[i] = BLUE;
    }
}

int main()
{
    //(vertex, graph_id)
    map<int, int> map;

    int n, m, u, v, res;
    int u_find, v_find;
    bool end = false;
    cin >> n;
    cin >> m;
    vector<int> graph[n + 1];
    pair<int, int> edges[m];
    int visit[n + 1];
    memset(visit, 0, (n + 1) * sizeof(int));
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        edges[i].first = u;
        edges[i].second = v;
    }

    for (int i = 0; i < m; i++)
    {
        u = edges[i].first;
        v = edges[i].second;
        //u_find, v_find
        if (map.find(u) == map.end())
            u_find = 0;
        else
        {
            u_find = 1;
        }
        if (map.find(v) == map.end())
            v_find = 0;
        else
        {
            v_find = 2;
        }

        switch (u_find | v_find)
        {
        case 0:
            makeGraph(graph, u, v, visit, map);
            break;
        //u have graph, v is not
        case 1:
            graph[u].push_back(v);
            graph[v].push_back(u);
            if (visit[u] == RED)
                visit[v] = BLUE;
            else
                visit[v] = RED;
            map.insert(make_pair(v, map.find(u)->second));
            break;
        //v have graph, u have not
        case 2:
            graph[u].push_back(v);
            graph[v].push_back(u);
            if (visit[v] == RED)
                visit[u] = BLUE;
            else
                visit[u] = RED;
            map.insert(make_pair(u, map.find(v)->second));
            break;
        //if they both part of graph
        case 3:
            if (map.find(u)->second == map.find(v)->second)
            {
                if (visit[u] == visit[v] && !end)
                {
                    res = i + 1;
                    end = true;
                }
                else
                {
                    graph[u].push_back(v);
                    graph[v].push_back(u);
                }
                
            }
            else
            {
                dfs(graph, u, v, visit, map, n);
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
            break;
        default:
            break;
        }
        if (end)
            break;
    }

    cout << res;
}