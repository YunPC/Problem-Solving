#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n = 1;
    int carrier_num = 0;
    int var;
    bool isfirst = true;
    vector<int>bags;
    bags.reserve(100000);
    float sum = 0;
    while (scanf("%d", &var) != EOF)
    {
            bags.emplace_back(var);
       
    }
    n = bags.front();
    bags.erase(bags.begin());
    sort(bags.begin(), bags.end(),  greater<>());
    register int size = bags.size();
    while(size >= 1)
    {
        switch (size)
        {
        case 1:
            ++carrier_num;
            size -= 1;
            break;
        
        default:
        if(bags.front() == n || bags.front() + bags.back() > n)
        {
            ++carrier_num;
            bags.erase(bags.begin());
            size -= 1;
        }
        else
        {
            bags.pop_back();
            bags.erase(bags.begin());
            size -= 2;
            ++carrier_num;

        }
            break;
        }
        
    }
    
    printf("%d\n", carrier_num);
    
    
    return 0;
}
