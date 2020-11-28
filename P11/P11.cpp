#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string words[1000];
vector<vector<int>> graph;
vector<string> answer;
vector<string> compare;
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
  //cout << answer[0] << " ";

  while(!s.empty())
  {
    int curr_word = s.top();
    s.pop();
    for(int i =0; i < graph[curr_word].size(); i++)
    {
      int next_word = graph[curr_word][i];

      if(visited[next_word] == false)
      {
        //cout << words[next_word] << " ";
        answer.push_back(words[next_word]);
        visited[next_word] = true;
        s.push(curr_word);
        s.push(next_word);
        break;
      }
    }
  }
  

}
int main() {
  
  int n;
  string s;
  bool isPossible = false;
  cin >> n;
  graph.reserve(n);
  //input
  for(int i = 0; i < n; i++)
  {
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
        //cout << i << ":" << j << endl;
      }
      if(isMatched(words[j], words[i]))
      {
        graph[j].push_back(i);
        //cout << i << ":" << j << endl;
      }
    }
  }
  //sort they lexicographical order

  //check if ever words chained
  for(int i = 0; i < n; i++)
  {
    dfs(i);
    //cout << answer.size();
    if(answer.size() == n)
    {
      for(int i = 0; i < n; i++)
      {
        cout << answer[i] << endl;
        isPossible = true;
      }
      break;
    }
    else
    {
      for(int i = 0; i < n; i++)
        visited[i] = false;
      answer.clear();
      //cout << "here";
    }
  }
  if(!isPossible)
    cout << "0";

}