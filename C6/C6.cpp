#include <iostream>

using namespace std;

int cards[50001];

int max_pick_card(int n, int pre_idx, int cur_idx, int card_cnt, bool decending);

int main()
{
    int n, card_num, max_n = 0, min_n = 0, pre_num= -1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> card_num;
        if(card_num == pre_num)
        {
            i--;
            n--;
            continue;
        }
        cards[i] = card_num;
        max_n = max(max_n, card_num);
        min_n = min(min_n, card_num);
        pre_num = card_num;
        
    }

    int max_interval = max_n - min_n;
    int comp_num = 0, last_idx = 0, card_cnt = 0, des_cnt = 0, res_cnt = 0; 
    long long sum = 0, res = 0, des_sum = 0;
    for (int idx = 1; idx <= n; idx++)
    {
        comp_num = cards[idx];
        for (int a_l = 1; a_l <= max_interval + 1; a_l++)
        {
            //init first card
            comp_num = cards[idx];
            last_idx = idx;
            sum = cards[idx];
            card_cnt = 1;
            des_sum = 0;
            des_cnt = 0;
            //checking for ascending part
            for (int i = idx+1; i <= n; i++)
            {
                //ascending
                if (cards[i] - comp_num <= a_l && cards[i] - comp_num > 0)
                {
                    sum += cards[i];
                    card_cnt++;
                    comp_num = cards[i];
                    last_idx = i;
                }
            }
            //checking for decending part
            if (last_idx != n)
            {
                // for (int d_l = 1; d_l <= max_interval+1; d_l++)
                // {
                //     des_sum = 0;
                //     des_cnt = 0;
                //     comp_num = cards[last_idx];
                //     for (int j = last_idx + 1; j <= n; j++)
                //     {
                        
                //         if (comp_num - cards[j] <= d_l && comp_num - cards[j] > 0)
                //         {
                //             des_sum += cards[j];
                //             des_cnt++;
                //             comp_num = cards[j];
                //         }
                //     }
                //     if (res < sum + des_sum)
                //     {
                //         res = sum + des_sum;
                //         res_cnt = card_cnt + des_cnt;
                //     }
                // }
                for(int d_idx = n; d_idx > last_idx; d_idx--)
                {
                    if(cards[d_idx] >= cards[last_idx])
                        continue;
                    for(int d_l = 1; d_l <= max_interval+1; d_l++)
                    {
                        comp_num = cards[d_idx];
                        des_sum = comp_num;
                        des_cnt = 1;
                        for(int j = d_idx-1; j > last_idx; j--)
                        {
                            if(cards[j] >= cards[last_idx])
                                continue;
                            if(cards[j]-comp_num <= d_l && cards[j]-comp_num > 0)
                            {
                                des_sum += cards[j];
                                des_cnt++;
                                comp_num = cards[j];
                            }

                        }
                        if(res < sum + des_sum)
                        {
                            res = sum + des_sum;
                            res_cnt = card_cnt + des_cnt;
                        }
                    }
                    
                }

            }
            if (res < sum + des_sum)
            {
                res = sum + des_sum;
                res_cnt = card_cnt + des_cnt;
            }
        }
    }
    std::cout << res << endl;
    std::cout << res_cnt;
    return 0;
}

int max_pick_card(int n, int comp_num, int cur_idx, int card_cnt, bool decending)
{
    int pick_res = 0, non_pick_res = 0, des_card_res = 0, res;
    if (cur_idx == n)
        return card_cnt;
    else
    {
        if (card_cnt == 0)
        {
            pick_res = max_pick_card(n, cards[cur_idx], cur_idx + 1, card_cnt + 1, decending);
            non_pick_res = max_pick_card(n, comp_num, cur_idx + 1, card_cnt, decending);
        }
        else
        {
            if (decending)
            {
                if (comp_num > cards[cur_idx])
                {
                    pick_res = max_pick_card(n, cards[cur_idx], cur_idx + 1, card_cnt + 1, decending);
                }

                non_pick_res = max_pick_card(n, comp_num, cur_idx + 1, card_cnt, decending);
            }
            else
            {
                if (comp_num < cards[cur_idx])
                {
                    pick_res = max_pick_card(n, cards[cur_idx], cur_idx + 1, card_cnt + 1, decending);
                }

                else if (comp_num > cards[cur_idx])
                    des_card_res = max_pick_card(n, cards[cur_idx], cur_idx + 1, card_cnt + 1, true);

                non_pick_res = max_pick_card(n, comp_num, cur_idx + 1, card_cnt, decending);
            }
        }
        res = max(pick_res, non_pick_res);
        res = max(res, des_card_res);
        return res;
    }
}
