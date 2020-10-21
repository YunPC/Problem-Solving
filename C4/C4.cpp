#include <iostream>
#include <algorithm>

using namespace std;

struct Pole{
    int pos;
    int l_pos_idx;
    int r_pos_idx;
};

struct Dist{
    int dist;
    int pos_idx;
};

struct Pole poles[100000];
struct Dist dist_arr[100000];

bool cmp_dist(const Dist &p1, const Dist &p2)
{
    if(p1.dist < p2.dist)
    {
        return true;
    }
    else if(p1.dist == p2.dist)
    {
        int p1idx = p1.pos_idx;
        int p1idxR = poles[p1idx].r_pos_idx;
        int p1idxL = poles[p1idx].l_pos_idx;
        int p2idx = p2.pos_idx;
        int p2idxR = poles[p2idx].r_pos_idx;
        int p2idxL = poles[p2idx].l_pos_idx;
        int p1comp = min(poles[p1idx].pos-poles[p1idxL].pos, poles[p1idxR].pos-poles[p1idx].pos);
        int p2comp = min(poles[p2idx].pos-poles[p2idxL].pos, poles[p2idxR].pos-poles[p2idx].pos);
        if( p1comp < p2comp )
            return true;
        else if( p1comp == p2comp )
        {
            if(p1.pos_idx < p2.pos_idx) return true;
            return false;
        }
        return false;
    }
    else
    {
        return false;
    }
    
    
}

bool cmp_pole(const Pole &p1, const Pole &p2)
{
    if(p1.pos < p2.pos)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

int main()
{   
    int n, k, pos;
    cin >> n >> k;
    //input
    for(int pole_idx = 0; pole_idx < n; pole_idx++)
    {
        cin >> pos;
        poles[pole_idx].pos = pos;
    }

    sort(poles, poles+n, cmp_pole);

    if(k == 2)
    {
        cout << poles[n-1].pos - poles[0].pos;
    }
    else
    {   
        for(int pole_idx = 0; pole_idx < n; pole_idx++)
        {
            if(pole_idx == 0)
            {
                poles[pole_idx].l_pos_idx = 0;
                poles[pole_idx].r_pos_idx = 1;
            }
            else if(pole_idx == n-1)
            {
                poles[pole_idx].r_pos_idx = n;
                poles[pole_idx].l_pos_idx = n-2;
            }
            else
            {
                poles[pole_idx].l_pos_idx = pole_idx-1;
                poles[pole_idx].r_pos_idx = pole_idx+1;
            }
            
             
        }
        for(int dist_idx = 1; dist_idx < n-1; dist_idx++)
        {
            dist_arr[dist_idx].dist = poles[dist_idx+1].pos - poles[dist_idx-1].pos;
            dist_arr[dist_idx].pos_idx = dist_idx;
        }

        sort(dist_arr+1, dist_arr+(n-1), cmp_dist);

        int dist_size = n-2;
        int dist_idx = 1;
        while (dist_size > k-2)
        {
            int to_del = dist_arr[dist_idx].pos_idx;
            int l_to_del = poles[to_del].l_pos_idx;
            int r_to_del = poles[to_del].r_pos_idx;
            poles[l_to_del].r_pos_idx = r_to_del;
            poles[r_to_del].l_pos_idx = l_to_del;
            for(int idx = dist_idx; idx < n-1; idx++)
            {
                if(dist_arr[idx].pos_idx == r_to_del)
                {
                    dist_arr[idx].dist = poles[poles[r_to_del].r_pos_idx].pos - poles[poles[r_to_del].l_pos_idx].pos;
                }
                else if(dist_arr[idx].pos_idx == l_to_del)
                {
                    dist_arr[idx].dist = poles[poles[l_to_del].r_pos_idx].pos - poles[poles[l_to_del].l_pos_idx].pos;
                }
            }
            dist_idx++;
            dist_size--;
            sort(dist_arr+dist_idx, dist_arr+(n-1), cmp_dist);

            
        }
        int idx = 0;
        int diff_min = 1000000000;
        while(poles[idx].r_pos_idx != n)
        {
            diff_min = min(poles[poles[idx].r_pos_idx].pos - poles[idx].pos, diff_min);
            idx = poles[idx].r_pos_idx;
        }
        cout << diff_min;

        // //array for a size(n-1)
        // for(int pole_idx = 1; pole_idx < n; pole_idx++)
        // {
        //     p2p_distance[pole_idx] = poles[pole_idx] - poles[pole_idx-1];
        // }

        // //array for b size(n-2)
        // for(int margin_idx = 1; margin_idx < n-1; margin_idx++)
        // {
        //     lr_margin[margin_idx].distance = p2p_distance[margin_idx] + p2p_distance[margin_idx+1];
        //     lr_margin[margin_idx].left_margin = p2p_distance[margin_idx];
        //     lr_margin[margin_idx].right_margin = p2p_distance[margin_idx+1];
        //     lr_margin[margin_idx].left_pos = poles[margin_idx-1];
        //     lr_margin[margin_idx].right_pos = poles[margin_idx+1];
        // }

        // //sort with b
        // sort(lr_margin+1, lr_margin+(n-1), cmp);

        // int pole_size = n-2;
        // int margin_idx = 1;
        // int delete_id;
        // //delete pole
        // while(pole_size > k-2)
        // {
        //     for(int id_idx = margin_idx; id_idx < n-1; id_idx++)
        //     {
        //         //adjacency left
        //         if(lr_margin[margin_idx].left_pos == lr_margin[id_idx].right_pos)
        //         {
        //             lr_margin[id_idx].right_margin += lr_margin[margin_idx].left_margin;
        //             lr_margin[id_idx].distance += lr_margin[margin_idx].left_margin;
        //             lr_margin[id_idx].right_pos = lr_margin[margin_idx].right_pos;
        //         }

        //         //adjacency right
        //         else if(lr_margin[margin_idx].right_pos == lr_margin[id_idx].left_pos)
        //         {
        //             lr_margin[id_idx].left_margin += lr_margin[margin_idx].right_margin;
        //             lr_margin[id_idx].distance += lr_margin[margin_idx].right_margin;
        //             lr_margin[id_idx].left_pos = lr_margin[margin_idx].left_pos;
        //         }
        //     }
        //     margin_idx++;
        //     pole_size--;
        //     //sort again
        //     sort(lr_margin+margin_idx, lr_margin+(n-1), cmp);
        // }
        
        // cout << min(lr_margin[margin_idx].left_margin, lr_margin[margin_idx].right_margin);

    }
    
    
    
    return 0;
}


