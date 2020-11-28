#include <iostream>
#include <vector>
#include <string>

using namespace std;

string words[1000];
int graph[1000][1000];
vector<string> answer;
bool isMatched(string s1, string s2)
{
  if(s1[s1.size()-1] == s2[0])
    return true;
  return false;
}

int m_strcmp(string s1, string s2)
{
    int i = 0;
    while(s1[i] != '0')
    {
        if(s1[i] != s2[i])
            break;
        i++;
    }
    return(s1[i] - s2[i]);
}
int main() {
  
  int n;
  string s;
  cin >> n;
  
  for(int i = 0; i < n; i++)
  {
    cin >> s;
    words[i] = s;
  }
  
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(i == j) continue;
      if(isMatched(words[i], words[j]))
      {
        graph[i][j] = 1;
      }
      if(isMatched(words[j], words[i]))
      {
        graph[j][i] = 1;
      }
    }
  }
  //sort they lexicographical order
    int sorted_index[n];
    for(int i = 0; i < n; i++)
    {
        sorted_index[i] = i;
    }
    for(int i = 0 ; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                continue;
            if(m_strcmp(words[sorted_index[i]], words[sorted_index[j]]) < 0)
            {
                int temp = sorted_index[i];
                sorted_index[i] = sorted_index[j];
                sorted_index[j] = temp;
            }
        }
    }
    for(int i = 0 ; i < n-1; i++)
    {
        if(graph[sorted_index[i]][sorted_index[i+1]] == 1)
            answer.push_back(words[sorted_index[i]]);
        else
            break;
        
    }
    
    answer.push_back(words[sorted_index[n-1]]);

    if(answer.size() == n)
    {
        for(int i = 0; i < n; i++)
            cout << answer[i] << endl;
    }
    else
        cout << 0;
    

}