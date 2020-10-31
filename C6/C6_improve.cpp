#include <iostream>

using namespace std;

int cards[50000];
struct Card
{
    int sum = 0;
    int cnt = 0;
};
Card asec_cards[50000];
Card des_cards[50000];


int main()
{
    int n, card_num, max_n = 0, min_n = 0, pre_num= -1;
    cin >> n;
    //input
    for (int i = 0; i < n; i++)
    {
        cin >> card_num;
        // if(card_num == pre_num)
        // {
        //     i--;
        //     n--;
        //     continue;
        // }
        cards[i] = card_num;
        pre_num = card_num;
        
    }

    int max_sum = 0, max_cnt = 0;
    //getting maximum increase
    for(int i = 0; i < n; i++)
    {
        max_sum = 0;
        max_cnt = 0;
        for(int j = i-1; j > -1; j--)
        {   
            //compare
            if(cards[j] < cards[i])
            {
                if(max_sum < asec_cards[j].sum)
                {
                    max_sum = asec_cards[j].sum;
                    max_cnt = asec_cards[j].cnt;
                }
                else if(max_sum == des_cards[j].sum + cards[j])
                {
                    if(max_cnt < des_cards[j].cnt + 1)
                    {
                        max_cnt = des_cards[j].cnt + 1;
                    }
                }
            }
        }
        //update
        asec_cards[i].sum = cards[i] + max_sum;
        asec_cards[i].cnt = 1 + max_cnt;
        
    }

    //getting minimum decrease
    for(int i = n-1; i > -1; i--)
    {
        max_sum = 0;
        max_cnt = 0;
        for(int j = i+1; j < n; j++)
        {
            //compare
            if(cards[i] > cards[j])
            {
                if(max_sum < des_cards[j].sum + cards[j])
                {
                    max_sum = des_cards[j].sum + cards[j];
                    max_cnt = des_cards[j].cnt + 1;
                }
                else if(max_sum == des_cards[j].sum + cards[j])
                {
                    if(max_cnt < des_cards[j].cnt + 1)
                    {
                        max_cnt = des_cards[j].cnt + 1;
                    }
                }
                
            }
        }

        //update
        des_cards[i].sum = max_sum;
        des_cards[i].cnt = max_cnt;
        
    }
    int sum = 0, res = 1;
    //get max value
    for(int i = 0; i < n; i++)
    {
        if(sum < asec_cards[i].sum + des_cards[i].sum)
        {
            sum = asec_cards[i].sum + des_cards[i].sum;
            res = asec_cards[i].cnt + des_cards[i].cnt;
        }
        else if(sum == asec_cards[i].sum + des_cards[i].sum)
            res = max(res, asec_cards[i].cnt + des_cards[i].cnt);
    }
    cout << res;

    return 0;
}

