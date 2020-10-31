#include <iostream>
#include <vector>
const int INF = 1000000000;
using namespace std;

int min_time(vector<int>& pipe);

int main()
{
    vector<int> pipe;
    pipe.reserve(50000);
    int n, len, len_sum, idx, time = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> len;
        pipe.push_back(len);

    }

    if(pipe.size() == 3)
    {
        int left[pipe.size()];
        int left_sum = 0, right_sum = 0;
        int gap = INF, idx;
        int right[pipe.size()];
        for(int i = 0; i < pipe.size(); i++)
        {
            left[i] = left_sum + pipe[i];
            left_sum += pipe[i];
        }
        for(int i = pipe.size()-1; i > -1; i--)
        {
            right[i] = right_sum + pipe[i];
            right_sum += pipe[i];
        }
        for(int i = 0; i < pipe.size()-1; i++)
        {
            if(abs(left[i] - right[i+1]) < gap)
            {
                idx = i;
                gap = abs(left[i] - right[i+1]);
            }
        }
        cout << left[idx]+right[idx+1];

    }
    else
    {
        cout << min_time(pipe);    
    }

    return 0;
}

int min_time(vector<int>& pipe)
{
    if(pipe.size() == 2)
        return pipe[0]+pipe[1];
    else if(pipe.size() == 1)
        return 0;
    else
    {
        int left[pipe.size()];
        int left_sum = 0, right_sum = 0;
        int gap = INF, idx;
        int right[pipe.size()];
        for(int i = 0; i < pipe.size(); i++)
        {
            left[i] = left_sum + pipe[i];
            left_sum += pipe[i];
        }
        for(int i = pipe.size()-1; i > -1; i--)
        {
            right[i] = right_sum + pipe[i];
            right_sum += pipe[i];
        }
        for(int i = 0; i < pipe.size()-1; i++)
        {
            if(abs(left[i] - right[i+1]) < gap)
            {
                idx = i;
                gap = abs(left[i] - right[i+1]);
            }
        }
        vector<int> left_v;
        vector<int> right_v;
        for(int i = 0; i <= idx; i++)
        {
            left_v.push_back(pipe[i]);
        }
        for(int i = idx + 1; i < pipe.size(); i++)
        {
            right_v.push_back(pipe[i]);
        }
        int left_res = min_time(left_v);
        int right_res = min_time(right_v);
        
        return left[idx]+right[idx+1] + left_res + right_res;

    }
    
}