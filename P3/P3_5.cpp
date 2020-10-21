#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int bags[100000];

int main()
{
    int n = 1;
    int carrier_num = 0;
    int var, idx = 0;
    bool isfirst = true;
    float sum = 0;
    int size;
    while (scanf("%d", &var) != EOF)
    {
            bags[idx] = var;
            ++idx;
       
    }
    n = bags[0];
    size = idx - 1;
    int left_idx = 1, right_idx = idx-1;
    sort(bags+1, bags+idx,  greater<>());
    while(size >= 1)
    {
        switch (size)
        {
        case 1:
            ++carrier_num;
            size -= 1;
            break;
        
        default:
        if(bags[left_idx] == n || bags[left_idx] + bags[right_idx] > n)
        {
            ++carrier_num;
            ++left_idx;
            size -= 1;
        }
        else
        {
            --right_idx;
            ++left_idx;
            size -= 2;
            ++carrier_num;

        }
            break;
        }
        
    }
    
    printf("%d", carrier_num);
    
    
    return 0;
}
