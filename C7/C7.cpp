#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

#define RED 1
#define BLUE 2

using namespace std;

bool dfs(int start, vector<int> graph[], int visit[])
{
    stack<int> s;
    int node, next_node, color = RED;
    s.push(start);
    if(visit[start] == 0)
        visit[start] = color;

    while (!s.empty())
    {
        node = s.top();
        s.pop();

        if(visit[node] == RED)
            color = BLUE;
        else
        {
            color = RED;
        }
        
        for(int i = 0; i < graph[node].size(); i++)
        {
            next_node = graph[node][i];

            if(visit[next_node] == 0)
            {
                visit[next_node] = color;
                s.push(node);
                s.push(next_node);
                break;
            }
            else
            {
                if(visit[next_node] == visit[node])
                    return true;
            }
            
        }
    }

    return false;
    

}

int main()
{
    int n, m, u, v;
    bool is_dangrous;
    cin >> n;
    cin >> m;
    vector<int> graph[n+1];
    int visit[n+1];
    fill(visit, visit+n+1, 0);

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);

        is_dangrous = dfs(u, graph, visit);
        memset(visit, 0, (n+1)*sizeof(int));
        if(is_dangrous)
        {
            cout << i+1;
            break;
        }

    }


}