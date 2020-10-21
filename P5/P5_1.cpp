#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line{
    int start_pos;
    int value;
};

struct Line f_func[1000001];
struct Line g_func[1000001];
struct Line fg_func[20000021];

int main()
{   

    int f_cnt, g_cnt;
    int f_value = 0, g_value = 0;
    int start_pos, value = 0;
    int p, q;

    cin >> f_cnt;

    for(int f_line = 0; f_line < f_cnt; f_line++)
    {
        cin >> start_pos >> value;
        f_func[f_line].start_pos = start_pos;
        f_func[f_line].value = value;
    }

    cin >> g_cnt;

    for(int g_line = 0; g_line < g_cnt; g_line++)
    {
        cin >> start_pos >> value;
        g_func[g_line].start_pos = start_pos;
        g_func[g_line].value = value;
        
    }

    cin >> p >> q;

    //merge
    int f_idx = 0, g_idx = 0, fg_idx = 0, fg_cnt;
    while(f_idx < f_cnt && g_idx < g_cnt)
    {
        if(f_func[f_idx].start_pos <= g_func[g_idx].start_pos)
        {
            fg_func[fg_idx] = f_func[f_idx];
            ++f_idx;
            ++fg_idx;
        }
        else
        {
            fg_func[fg_idx] = g_func[g_idx];
            ++g_idx;
            ++fg_idx;
        }
        
    }
    if(f_idx < f_cnt)
    {
        for(;f_idx < f_cnt; f_idx++)
        {
            fg_func[fg_idx] = f_func[f_idx];
            ++fg_idx;
        }
    }
    else
    {
        for(;g_idx < g_cnt; g_idx++)
        {
            fg_func[fg_idx] = g_func[g_idx];
            ++fg_idx;
        }
    }
    fg_cnt = fg_idx;
  
    int current_pos = p;
    long long res = 0;
    value = 0;
    int fg_start = 0, fg_end = fg_cnt;
    while(fg_start < fg_cnt)
    {
        if(p > fg_func[fg_start].start_pos)
        {
            value = max(value,fg_func[fg_start].value);
            ++fg_start;
     
        }
        else
        {
            break;
        }
        
    }
    while(fg_start < fg_end)
    {
        if(q < fg_func[fg_end-1].start_pos)
        {
            --fg_end;
        }
        else
        {
            break;
        }
        
    }
    fg_idx = fg_start;
    while (fg_idx < fg_end)
    {
        res += ((fg_func[fg_idx].start_pos - current_pos)%10007) * (value%10007);
        res %= 10007;
        value = max(value, fg_func[fg_idx].value);
        current_pos = fg_func[fg_idx].start_pos;
        ++fg_idx;
    }
    
    res += ((q+1 - current_pos)%10007) * (value%10007);
    res %= 10007;
    
    cout << res;
    return 0;
}


