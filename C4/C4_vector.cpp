#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int poles[100000];

struct Dist{
    int margin;
    Dist* left = NULL;
    Dist* right = NULL;
};

struct Dist* ptr_arr[100000];
struct Dist margin[100000];

bool cmp_dist(const Dist* p1, const Dist* p2)
{
    if(p1->margin < p2->margin)
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
    
    //while(1)
    //{
    int n,k;
    int pos;
    cin >> n >> k;

    //input
    for(int pole_idx = 0; pole_idx < n; pole_idx++)
    {
        cin >> pos;
        poles[pole_idx] = pos;
    }
    sort(poles, poles+n);
    if(k == 2)
    {
        cout << poles[n-1] - poles[0];
    }
    else
    {
        //array for a
    for(int margin_idx = 0; margin_idx < n-1; margin_idx++)
    {
        //put margin value
        margin[margin_idx].margin = poles[margin_idx+1] - poles[margin_idx];

        //set neighbor pole
        if(margin_idx == 0)
        {
            margin[margin_idx].right = &margin[margin_idx+1];
        }
        else if(margin_idx == n-2)
        {
            margin[margin_idx].left = &margin[margin_idx-1];
        }
        else
        {
            margin[margin_idx].left = &margin[margin_idx-1];
            margin[margin_idx].right = &margin[margin_idx+1];
        }
        
    }

    //initialize array list
    for(int ptr_idx = 0; ptr_idx < n-1; ptr_idx++)
    {
        ptr_arr[ptr_idx] = &margin[ptr_idx];
    }
    
    int ptr_idx = 0;
    sort(ptr_arr, ptr_arr+(n-1), cmp_dist);
    int pole_size = k-1, margin_size = n-1;
    int cmp_margin, same_idx, sum_margin = 0, temp_margin = 0, delete_idx;
    int left_margin = 0, right_margin = 0;
    Dist* temp_ele = NULL;
    while(margin_size > pole_size)
    {
        sum_margin = 0;
        left_margin = 0;
        right_margin = 0;
        same_idx = ptr_idx+1;
        cmp_margin = ptr_arr[ptr_idx]->margin;
        sum_margin = cmp_margin;

        //pick out the first element of ptr_arr
        delete_idx = ptr_idx;
        // if(ptr_arr[ptr_idx]->left != NULL)
        //     sum_margin += ptr_arr[ptr_idx]->left->margin;
        // if(ptr_arr[ptr_idx]->right != NULL)
        //     sum_margin += ptr_arr[ptr_idx]->right->margin;
        for(Dist* left_pole = ptr_arr[ptr_idx]; left_pole->left != NULL; left_pole = left_pole->left)
            {
                left_margin += left_pole->margin;
            }
        for(Dist* rigth_pole = ptr_arr[ptr_idx]; rigth_pole->right != NULL; rigth_pole = rigth_pole->right)
            {
                right_margin += rigth_pole->margin;
            }
        sum_margin = min(left_margin, right_margin);

        //if there is several element same as ptr_margin OUTOFINDEX!!!!
        while(cmp_margin == ptr_arr[same_idx]->margin)
        {
            temp_margin = 0;
            left_margin = 0;
            right_margin = 0;
            // if(ptr_arr[same_idx]->left != NULL)
            //     temp_margin += ptr_arr[same_idx]->left->margin;
            // if(ptr_arr[same_idx]->right != NULL)
            //     temp_margin += ptr_arr[same_idx]->right->margin;
            // temp_margin += ptr_arr[same_idx]->margin;
            for(Dist* left_pole = ptr_arr[same_idx]; left_pole->left != NULL; left_pole = left_pole->left)
            {
                left_margin += left_pole->margin;
            }
            for(Dist* rigth_pole = ptr_arr[same_idx]; rigth_pole->right != NULL; rigth_pole = rigth_pole->right)
            {
                right_margin += rigth_pole->margin;
            }
            temp_margin = min(left_margin, right_margin);
            if(temp_margin < sum_margin)
            {
                sum_margin = temp_margin;
                delete_idx = same_idx;
            }
            same_idx++;
            if(same_idx > n-2)
                break;
        }
        //swap two element
        temp_ele = ptr_arr[ptr_idx];
        ptr_arr[ptr_idx] = ptr_arr[delete_idx];
        ptr_arr[delete_idx] = temp_ele;
        
        left_margin = 0;
        right_margin = 0;
        //link elements
        //both exist
        if(ptr_arr[ptr_idx]->left != NULL && ptr_arr[ptr_idx]->right != NULL)
        {
            ptr_arr[ptr_idx]->left->right = ptr_arr[ptr_idx]->right;
            ptr_arr[ptr_idx]->right->left = ptr_arr[ptr_idx]->left;
            
            for(Dist* left_pole = ptr_arr[ptr_idx]; left_pole->left != NULL; left_pole = left_pole->left)
            {
                left_margin += left_pole->margin;
            }
            for(Dist* rigth_pole = ptr_arr[ptr_idx]; rigth_pole->right != NULL; rigth_pole = rigth_pole->right)
            {
                right_margin += rigth_pole->margin;
            }
            if(left_margin < right_margin)
                ptr_arr[ptr_idx]->left->margin += ptr_arr[ptr_idx]->margin;
            else
            {
                ptr_arr[ptr_idx]->right->margin += ptr_arr[ptr_idx]->margin;
            }
            
        }
        //only left exist
        else if(ptr_arr[ptr_idx]->left != NULL)
        {
            ptr_arr[ptr_idx]->left->right = ptr_arr[ptr_idx]->right;
            ptr_arr[ptr_idx]->left->margin += ptr_arr[ptr_idx]->margin;
        } 
        //only right exist
        else if(ptr_arr[ptr_idx]->right != NULL)
        {
            ptr_arr[ptr_idx]->right->left = ptr_arr[ptr_idx]->left;
            ptr_arr[ptr_idx]->right->margin += ptr_arr[ptr_idx]->margin;
        }

        ptr_idx++;
        margin_size--;
        sort(ptr_arr+ptr_idx, ptr_arr+(n-1), cmp_dist);
    }

        cout << ptr_arr[ptr_idx]->margin;
    }
    //}
    return 0 ;
}