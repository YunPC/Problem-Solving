#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string words[1000];
vector<int> graph[26];
bool is_end = false;
int word_id[1000] = {0};

void recursive(int start, vector<string> answer, int n, int visitied)
{
  answer.push_back(words[start]);
  if(answer.size() == n)
  {
    for(int i = 0; i < n; i++)
    {
      cout << answer[i] << endl;
      is_end = true;
    }
      
  }
  for(auto idx : graph[words[start][words[start].size()-1]-97])
  {
    if(word_id[idx] != visitied)
    {
      word_id[idx] = visitied;
      recursive(idx, answer, n, visitied);
    }
      
  }
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
  sort(words, words+n);

  //check if word list can be chained
  int start[26] = {0};
  int end[26] = {0};
  int subtract[26] = {0};

  for(int i = 0; i < n; i++)
  {
    start[words[i][0]-97]++;
    end[words[i][words[i].size()-1]-97]++;
  }

  for(int i = 0; i < 26; i++)
  {
    subtract[i] = start[i] - end[i];
  }

  int essential_start = 0;
  int essential_char = -1;
  int essential_end = 0;
  vector<string> answer;
  for(int i = 0; i < 26; i++)
  {
    if(subtract[i] > 0)
    {
      essential_start++;
      essential_char = i;
    }
    else if(subtract[i] < 0)
      essential_end++;
  }
  vector<string> str_v;
  if(essential_start > 1)
    cout << 0;
  else if(essential_end > 1)
    cout << 0;
  else
  {
    //make list with sorted word
    for(int i = 0; i < n; i++)
    {
      graph[words[i][0]-97].push_back(i);
    }
    if(essential_char != -1)
    {
      for(int i = 0; i < n; i++)
      {
        
        if(words[i][0]-97 == essential_char)
        {
          recursive(i, str_v, n, 1);
          break;
        }
      }
      
    }
    else
    {
      for(int i = 0; i < n; i++)
      {
        recursive(i, str_v, n, i+1);
      }
      
    }
    if(!is_end)
      cout << 0;
    
  }

  return 0;

}