#include <iostream>
#include <vector>
#include <algorithm>
const int INF = 2000000001;

using namespace std;

struct Line{
    int start_pos;
    int value;
    Line(int start_pos, int value){
        this ->start_pos = start_pos;
        this -> value = value;
    }
};


int main()
{   
    vector<Line> f_func;
    vector<Line> g_func;

    int f_cnt, g_cnt;
    int f_value = 0, g_value = 0;
    int start_pos, value;
    int p, q;

    cin >> f_cnt;

    for(int f_line = 0; f_line < f_cnt; f_line++)
    {
        cin >> start_pos >> value;
        f_func.push_back(Line(start_pos, value));
    }

    cin >> g_cnt;

    for(int g_line = 0; g_line < g_cnt; g_line++)
    {
        cin >> start_pos >> value;
        g_func.push_back(Line(start_pos, value));
    }

    cin >> p >> q;
    
    int point = p, next_fpoint = INF, next_gpoint = INF;
    long long res = 0, temp;
    while (point < q+1)
    {
        
        while(!f_func.empty())
        {
            if(point >= f_func.front().start_pos)
            {
                f_value = max(f_value, f_func.front().value);
                f_func.erase(f_func.begin());
                next_fpoint = INF;
            }
            else
            {   
                next_fpoint = f_func.front().start_pos;
                break;
            }
   
        }
        while(!g_func.empty())
        {
            if(point >= g_func.front().start_pos)
            {
                g_value = max(g_value, g_func.front().value);
                g_func.erase(g_func.begin());
                next_gpoint = INF;
            }
            else
            {
                next_gpoint = g_func.front().start_pos;
                break;
            }
            
        }
        
        if(p == q)
        {
          res += max(f_value, g_value);
          ++point;
        }
        else if(next_fpoint != INF || next_gpoint != INF)
        {
            temp = max(f_value, g_value);
            temp *= (min(q-point,min(next_fpoint, next_gpoint) - point));
            res += temp;
            point += (min(next_fpoint, next_gpoint) - point);
        }
        else
        {
            temp = max(f_value, g_value);
            temp *= (q - point + 1);
            res += temp;
            point += (q - point + 1);
        }
    
        
    }
    
    cout << res % 10007;
    return 0;
}


