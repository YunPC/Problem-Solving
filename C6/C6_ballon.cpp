#include <iostream>
#include <vector>

using namespace std;

int cards[20];
int ascending[20];
int descending[20];

vector<pair<int, int>> temp_cnt;

int binarySearch(int size, int d);

int main()
{
    int n, card_num;
    temp_cnt.reserve(50000);
    cin >> n;
    //input
    for (int i = 0; i < n; i++)
    {
        cin >> card_num;
        
        cards[i] = card_num;
    }

    vector<pair<int, int>>::iterator iter, insert_iter;
    bool is_last;
    //ascending
    for(int i = 0; i < n; i++)
    {
        if(temp_cnt.size() == 0)
        {
            temp_cnt.push_back(pair<int, int>(cards[i], 1));
            ascending[i] = 1;
        }
        else
        {
            int idx = binarySearch(temp_cnt.size(), cards[i]);
            //if there is value
            if(idx != -1)
            {
                if(idx == 0)
                {
                    ascending[i] = temp_cnt[idx].second;
                    continue;
                }
                int temp = 0;
                for(int j = 0; j < idx; j++)
                {
                    temp = max(temp, temp_cnt[j].second);
                }

                temp_cnt[idx].second = temp+1;
                ascending[i] = temp+1;

                
            }
            //if there is no value
            else
            {
                is_last = true;
                for(iter = temp_cnt.begin(); iter != temp_cnt.end(); iter++)
                {
                    if(iter->first < cards[i])
                    {
                        insert_iter = iter;
                        is_last = false;
                    }
                }
                if(is_last)
                {
                    //last
                    if(temp_cnt[0].first < cards[i])
                    {
                        temp_cnt.push_back(pair<int, int>(cards[i], temp_cnt.back().second+1));
                        ascending[i] = temp_cnt.back().second+1;
                
                    }
                    //first
                    else
                    {
                        temp_cnt.insert(temp_cnt.begin(), pair<int, int>(cards[i], 1));
                        ascending[i] = 1;
                    }
                }
                else
                {
                    temp_cnt.insert(++insert_iter, pair<int, int>(cards[i], insert_iter->second+1));
                    ascending[i] = insert_iter->second;
                }
                
            }
            
        }
        
    }
    
    temp_cnt.clear();

    //descending
    for(int i = n-1; i > -1; i--)
    {
        if(temp_cnt.size() == 0)
        {
            temp_cnt.push_back(pair<int, int>(cards[i], 1));
            descending[i] = 1;
        }
        else
        {
            int idx = binarySearch(temp_cnt.size(), cards[i]);
            //if there is value
            if(idx != -1)
            {
                if(idx == 0)
                {
                    descending[i] = temp_cnt[idx].second;
                    continue;
                }
                int temp = 0;
                for(int j = 0; j < idx; j++)
                {
                    temp = max(temp, temp_cnt[j].second);
                }

                temp_cnt[idx].second = temp+1;
                descending[i] = temp+1;
                
            }
            //if there is no value
            else
            {
                is_last = true;
                for(iter = temp_cnt.begin(); iter != temp_cnt.end(); iter++)
                {
                    if(iter->first < cards[i])
                    {
                        insert_iter = iter;
                        is_last = false;
                    }
                }
                if(is_last)
                {
                    //last
                    if(temp_cnt[0].first < cards[i])
                    {
                        temp_cnt.push_back(pair<int, int>(cards[i], temp_cnt.back().second+1));
                        descending[i] = temp_cnt.back().second+1;
                
                    }
                    //first
                    else
                    {
                        temp_cnt.insert(temp_cnt.begin(), pair<int, int>(cards[i], 1));
                        descending[i] = 1;
                    }
                    
                }    
                else
                {
                    temp_cnt.insert(++insert_iter, pair<int, int>(cards[i], insert_iter->second+1));
                    descending[i] = insert_iter->second;
                }
                
            }
            
        }
    }
    int res = -1, a_cnt, d_cnt = 0;
    for(int i = 0; i < n; i++)
    {
        a_cnt = ascending[i];
        d_cnt = 0;
        for(int j = i; j < n; j++)
        {
            if(cards[i] > cards[j])
            {
                d_cnt = max(d_cnt, descending[j]);
            }
        }
        res = max(res, a_cnt+d_cnt);
    }

        cout << res;
    
    


    return 0;
}

int binarySearch(int size, int d)
{
    int s = 0;
    int e = size-1;
    int m;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (temp_cnt[m].first == d) return m;
        else if (temp_cnt[m].first > d) e = m - 1;
        else s = m + 1;
    }
    
    return -1;
}