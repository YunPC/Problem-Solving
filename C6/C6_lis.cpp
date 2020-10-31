#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, c, a_cnt = 0, idx, d_cnt = 0, res = 0;
    vector<int> cards, a_list, a_cnt_list, d_list, d_cnt_list;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> c;
        cards.push_back(c);
    }

    //ascending
    for(int i = 0; i < n; i++)
    {
        if(a_list.empty())
        {
            a_list.push_back(cards[i]);
            a_cnt++;
            a_cnt_list.push_back(a_cnt);
        }
        else
        {
            if(a_list.back() < cards[i])
            {
                a_list.push_back(cards[i]);
                a_cnt++;
                a_cnt_list.push_back(a_cnt);
            }
            else
            {
                idx = -1;
                for(int j = a_list.size()-2; j > -1; j--)
                {
                    if(a_list[j] < cards[i])
                    {
                        idx = j;
                        break;
                    }   
                }
                a_list[++idx] = cards[i];
                a_cnt_list.push_back(a_cnt);
            }
            
        }
        
    }

    //descending
    for(int i = 0; i < n; i++)
    {
        if(d_list.empty())
        {
            d_list.push_back(cards[n-1-i]);
            d_cnt++;
            d_cnt_list.push_back(d_cnt);
        }
        else
        {
            if(d_list.back() < cards[n-1-i])
            {
                d_list.push_back(cards[n-1-i]);
                d_cnt++;
                d_cnt_list.push_back(d_cnt);
            }
            else
            {
                idx = -1;
                for(int j = d_list.size()-2; j > -1; j--)
                {
                    if(d_list[j] < cards[n-1-i])
                    {
                        idx = j;
                        break;
                    }
                }
                d_list[++idx] = cards[n-1-i];
                d_cnt_list.push_back(d_cnt);
            }
            
        }
        
    }
    
    //match
    for(int i = 0; i < n; i++)
    {
        res = max(res, a_cnt_list[i]+d_cnt_list[n-1-i]);
    }

    cout << res -1;
    return 0;
}