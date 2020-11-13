#include <iostream>
#include <queue>
#include <stack>

using namespace std;


struct comp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
        {
            return a.first < b.first;
        }
    
};
int main()
{

    int n, t, p, v, end;
    cin >> n >> t;

    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    for(int i = 0; i < n; i++)
    {
        cin >> p >> v;
        end = p + (v*t);
        pq.push(make_pair(end, p));
    }

    pair<int, int> f;
    stack<pair<int, int>> s;
    f = pq.top();
    pq.pop();
    s.push(f);
    while (!pq.empty())
    {
        f = pq.top();
        if(s.empty())
        {
            s.push(f);
            pq.pop();
        }
        else if(s.top().second < f.second)
            s.pop();
        else
        {
            s.push(f);
            pq.pop();
        }
        
    }
    
    cout << s.size();
    return 0;
}