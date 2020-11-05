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
                    return false;
            }
            
        }
    }

    return true;
    

}

void delEdge(vector<int> graph[], int u, int v) 
{ 
    for (int i = 0; i < graph[u].size(); i++) { 
        if (graph[u][i] == v) { 
            graph[u].erase(graph[u].begin() + i); 
            break; 
        } 
    } 
  
    for (int i = 0; i < graph[v].size(); i++) { 
        if (graph[v][i] == u) { 
            graph[v].erase(graph[v].begin() + i); 
            break; 
        } 
    } 
} 

void addEdge(vector<int> graph[], int u, int v) 
{ 
    graph[u].push_back(v); 
    graph[v].push_back(u); 
} 

int main()
{
    int n, m, u, v;
    bool is_dangrous;
    cin >> n;
    cin >> m;
    vector<int> graph[n+1];
    pair<int, int> pair[m+1];
    int visit[n+1];
    fill(visit, visit+n+1, 0);

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        pair[i+1].first = u;
        pair[i+1].second = v;
        
    }

    int left = 1, right = m, res = -1, mid;
    bool isBipartiteGraph;
    //binary search
    while (left <= right)
    {
        mid = (left+right)/2;
            
        //this case addedge
        if(isBipartiteGraph)
        {
            for(int i = left; i <= mid; i++)
            {
                addEdge(graph, pair[i].first, pair[i].second);
            }
        }
        else
        {
            for(int i = mid+1; i <= right; i++)
            {
                delEdge(graph, pair[i].first, pair[i].second);
            }
        }
        

        memset(visit, 0, (n+1)*sizeof(int));
        
        isBipartiteGraph = false;
        
        for (int i = 1; i <= n; i++) { 
            if (!visit[i]) { 
                if(dfs(i, graph, visit))
                {
                    
                    left = mid + 1;
                    isBipartiteGraph = true;
                }
            } 
        }
        if(!isBipartiteGraph)
        {
            res = max(res, mid);
            right = mid;
            if(mid == m)
                break;
        }
        
    }
    cout << mid;

}