# include <iostream>
# include <string.h>
# include <vector>
# include <algorithm>
# include <time.h>

using namespace std;

int makeTeam(vector<int>& soldiers, int k, vector<int> adj[]);
void addEdge(vector<int> adj[], int u, int v);


int main()
{
    
    
    int n, k, f;
    int person1, person2;
    int candidate_num = 0;

    cin >> n >> k >> f;
    vector<int> candidate;
    
    vector<int> adj[n+1];
     for(int idx = 0 ; idx < f; idx++)
     {
         cin >> person1 >> person2;
         addEdge(adj, person1, person2);
     }
    for(int i= 1; i < n+1; i++)
    {
        if(adj[i].size() >= k)
        {
            candidate.push_back(i);
            candidate_num++;
        }
    }
    
    if(candidate_num < k+1)
    {
        cout << 0 << endl;
    }
    else{
        int result;
        result = makeTeam(candidate, k, adj);
        cout << result << endl;
        
    }
   
    return 0;
}

void addEdge(vector<int> adj[], int u, int v)
{
   
    adj[u].push_back(v);
    adj[v].push_back(u);
    
}

int makeTeam(vector<int>& soldiers, int k, vector<int> adj[]){
    int result = soldiers.size();
    if(soldiers.size() < k+1)
        return 0;
    else
    {
       
        for(int i =0; i < soldiers.size(); i++)
        {
            int friend_num = 0;
            int soldier_num = soldiers[i];
            for (auto soldier_friend : adj[soldier_num])
            {
                if(find(soldiers.begin(), soldiers.end(), soldier_friend) != soldiers.end()){
                    friend_num++;
                }
            }
            if(friend_num < k)
            {
                soldiers.erase(soldiers.begin() + i);
                result = makeTeam(soldiers, k, adj);
                break;
            }
            
        }
        
        return result;
    }
    
        
}