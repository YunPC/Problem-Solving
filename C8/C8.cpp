#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct comp {
    constexpr bool operator()(
        pair<float, float> const& a,
        pair<float, float> const& b)
        const noexcept
        {
            return a.first > b.first;
        }
    
};

int main()
{
    int n, d, x, y;
    cin >> n >> d;

    pair<int, int> v[n];
    priority_queue<pair<float, float>, vector<pair<float, float>>, comp> pq;
    //input
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        v[i].first = x;
        v[i].second = y;
    }
    //make section
    for(int i = 0; i < n; i++)
    {
        x = v[i].first;
        y = v[i].second;
        //this will be spot
        if(d == y)
            pq.push(make_pair(x, x));
        //if they have section
        else
        {
            float end_p = sqrt(pow(d,2) - pow(y,2)) - x;
            end_p *= -1;
            if(end_p < x)
                pq.push(make_pair(end_p, end_p+(x-end_p)*2));
            else
                pq.push(make_pair(end_p -(end_p-x)*2, end_p));
            
        }      
    }
    //calculate wells
    int res = 0;
    while(!pq.empty())
    {
        res++;
        pair<float, float> s = pq.top();
        pq.pop();
        int end_s = s.second;
        while (!pq.empty())
        {
            pair<float, float> new_s = pq.top();
            if(new_s.first <= end_s)
            {   
                if(new_s.second < end_s)
                    end_s = new_s.second;
                pq.pop();
            }
            else
                break;
        }
    }
    cout << res;
}