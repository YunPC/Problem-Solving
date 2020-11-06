#include<iostream>

using namespace std;

int main()
{
    int n, m, u, v;
    cin >> n;
    cin >> m;

    int root[n+1];
    int days[n+1];
    int arr[m][2];

    for(int i = 1; i <= n; i++)
    {
        root[i] = i;
    }

    for(int i = 1; i <=n; i++)
    {
        days[i] = 0;
    }

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        arr[i][0] = u;
        arr[i][1] = v;
    }

    for(int i = 0; i < m; i++)
    {
        u = arr[i][0];
        v = arr[i][1];
        
        if(root[u] == root[v])
        {
            if(days[u] == days[v])
            {
                cout << i+1;
                break;
            }
            
            else
            {
                continue;
            }
        }
        
        else
        {
            
            if(days[u] != 0 && days[v] != 0)
            {
                int temp = root[v];
                if(days[u] == days[v])
                {
                    for(int j = 1; j <= n; j++)
                    {
                        if(root[j] == temp)
                        {
                            root[j] = root[u];
                            if(days[j] == 1)
                                days[j] = 2;
                            else
                                days[j] = 1;
                        }
                    }
                }
                else
                {
                    
                    for(int j = 1; j <= n; j++)
                    {
                        if(root[j] == temp)
                            root[j] = root[u];
                    }
                }
                
            }
            else
            {
                if(days[u] != 0 || days[v] != 0)
                {
                    if(days[u] != 0)
                    {
                        root[v] = root[u];
                        if(days[u] == 1)
                            days[v] = 2;
                        else
                            days[v] = 1;
                        
                    }
                    else
                    {
                        root[u] = root[v];
                        if(days[v] == 1)
                            days[u] = 2;
                        else
                            days[u] = 1;
                        
                    }
                    
                }
                
                else
                {
                    root[v] = root[u];
                    days[u] = 1;
                    days[v] = 2;
                }
                
            }
        }
        

    }

}