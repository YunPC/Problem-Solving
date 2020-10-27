#include <iostream>

using namespace std;

int cards[50000];

int max_pick_card(int n, int pre_idx, int cur_idx, int card_cnt, bool decending);

int main()
{
    int n, card_num;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> card_num;
        cards[i] = card_num;
    }
    if(n == 1)
        cout << 1;
    else
    {
        cout << max_pick_card(n, cards[0], 0, 0, false);    
    }

    return 0;

}

int max_pick_card(int n, int comp_num, int cur_idx, int card_cnt, bool decending){
    int pick_res= 0, non_pick_res= 0, des_card_res = 0, res;
    if(cur_idx == n)
        return 0;
    else
    {
        if(card_cnt == 0)
        {
            pick_res = 1 + max_pick_card(n, cards[cur_idx], cur_idx+1, card_cnt+1, decending);
            non_pick_res = max_pick_card(n, comp_num, cur_idx+1, card_cnt, decending);
        }
        else
        {
            if(decending)
            {   //choose
                if(comp_num > cards[cur_idx])
                {
                    pick_res = 1 + max_pick_card(n, cards[cur_idx], cur_idx+1, card_cnt+1, decending);
                }
                //no choose
                non_pick_res = max_pick_card(n, comp_num, cur_idx+1, card_cnt, decending);
                
            }
            else
            {
                if(comp_num < cards[cur_idx])
                {
                    pick_res = 1 + max_pick_card(n, cards[cur_idx], cur_idx+1, card_cnt+1, decending);
                }
                    

                else if(comp_num > cards[cur_idx])
                    des_card_res = 1 + max_pick_card(n, cards[cur_idx], cur_idx+1, card_cnt+1, true);

                non_pick_res = max_pick_card(n, comp_num, cur_idx+1, card_cnt, decending);
                
            }
            
                
        }
        res = max(pick_res, non_pick_res);
        res = max(res, des_card_res);
        return res;
    }
    

}