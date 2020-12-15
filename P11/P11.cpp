#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string words[1000];
vector<string> answer;
vector<int> graph[1000];
int start[26];
int end[26];
int subtract[26];
bool visited[1000];

bool isMatched(string s1, string s2)
{
  if(s1[s1.size()-1] == s2[0])
    return true;
  return false;
}

void dfs(int start)
{
  stack<int> s;
  s.push(start);
  visited[start] = true;
  answer.push_back(words[start]);
  
  while(!s.empty())
  {
    int curr_word = s.top();
    s.pop();
    for(int i =0; i < graph[curr_word].size(); i++)
    {
      int next_word = graph[curr_word][i];

      if(visited[next_word] == false)
      {
        answer.push_back(words[next_word]);
        visited[next_word] = true;
        s.push(curr_word);
        s.push(next_word);
        break;
      }
    }
  }
  

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
    cin >> n;
    //input
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        words[i] = s;
    }
    //check if two words get matched
    for(int i = 0; i < n; i++)
    {
      for(int j = i+1; j < n; j++)
      {
        if(isMatched(words[i], words[j]))
        {
          graph[i].push_back(j);
        }
        if(isMatched(words[j], words[i]))
        {
          graph[j].push_back(i);
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
    //count start and end character
    for (int i = 0; i < n; i++) {
        start[words[i][0]-97]++;
        ::end[words[i][words[i].size()-1]-97]++;
    }
    //subtract start and end count
    for(int i = 0; i < 26; i++)
    {
        subtract[i] = start[i] - ::end[i];
    }
    //find essential start point and end point
    int essential_start = 0;
    int start_char = -1;
    int essential_end = 0;

    for(int i = 0; i < 26; i++)
    {
        if(subtract[i] > 0)
        {
            essential_start++;
            start_char = i;
        }
        else if(subtract[i] < 0)
            essential_end++;
    }
    if(essential_start > 1)
      cout << 0;
    else if(essential_end > 1)
      cout << 0;
    else
    {
      if(start_char != -1)
      {
        for(int i = 0 ; i < n; i++)
        {
          if(words[i][0]-97 == start_char)
          {
            dfs(start_char);
            if(answer.size() == n)
            {
              for(int i = 0; i < n; i++)
              {
                cout << answer[i] << endl;
              }
              break;
            }
            else
            {
              for(int i = 0; i < n; i++)
              {
                visited[i] = false;
              }
              answer.clear();
            }
          }
        }
        
      }
      else
      {
        for(int i = 0; i < n; i++)
        {
          dfs(sorted_index[i]);
          if(answer.size() == n)
          {
            for(int i = 0; i < n; i++)
            {
              cout << answer[i] << endl;
            }
            break;
          }
          else
          {
            for(int i = 0; i < n; i++)
            {
              visited[i] = false;
            }
            answer.clear();
          }
          
        }
      }
      if(answer.size() == 0)
        cout << 0;
    }
    

    return 0;

}