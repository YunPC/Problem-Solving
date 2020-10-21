
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
   int splitArray(vector<int>& v, int m) {
      int n = v.size();
      vector <int> dp(n);
      vector <int> sum(n);
      sum[0] = v[0];
      for(int i =1;i<n;i++)sum[i] =sum[i-1]+v[i];
      dp[0] = sum[n-1];
      for(int i =1;i<n;i++){
         dp[i] = sum[n-1] - sum[i-1];
      }
      for(int i =1;i<m;i++){
         for(int start = 0;start<n-i;start++){
            for(int end = start+1;end<=n-i;end++){
               dp[start] = min(dp[start],max((start==0?sum[end-1]:sum[end-1]-sum[start-1]),dp[end]));
            }
         }
      }
      return dp[n-1];
   }
};
int poles[100000];
main(){

    int n, k, pos;
    cin >> n >> k;
    Solution ob;
    vector<int> v;

    for(int pole_idx = 0; pole_idx < n; pole_idx++)
    {
        cin >> pos;
        poles[pole_idx] = pos;
    }

    sort(poles, poles+n);

    for(int margin_idx = 0; margin_idx < n-1; margin_idx++)
    {
        v.push_back(poles[margin_idx+1] - poles[margin_idx]); 
    } 
   
   cout << (ob.splitArray(v, k-1));
}