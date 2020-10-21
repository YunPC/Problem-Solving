#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n = 1;
    int weight;
    int carrier_num = 0;
    int var;
    vector<int> small_bags;
    vector<int> big_bags;
    bool isfirst = true;
    
    
    while (cin >> var)
    {
        if(isfirst)
        {
            n = var;
            isfirst = false;
        }
        else
        {
            weight = var;
            if(weight == 0)
                continue;
            if(weight == n)
            {
                carrier_num++;
            }
            else if(weight > n/2)
            {
               big_bags.push_back(weight);     
            }
            else
            {
                small_bags.push_back(weight);
            }
            weight = 0;
            
        }
       
    }

    sort(big_bags.begin(), big_bags.end(), greater<int>());
    sort(small_bags.begin(), small_bags.end());

    while (!(big_bags.empty() || small_bags.empty()))
    {
        if(big_bags.front() + small_bags.front() <= n)
        {
            carrier_num++;
            big_bags.erase(big_bags.begin());
            small_bags.erase(small_bags.begin());
        }
        else if(big_bags.size() > 0)
        {
            carrier_num++;
            big_bags.erase(big_bags.begin());
        }
    }
    
    if(big_bags.size() > 0)
    {
        carrier_num += big_bags.size();
    }
    if(small_bags.size() > 0)
    {
        if(small_bags.size() % 2 == 0)
            carrier_num += small_bags.size()/2;
        else
        {
            carrier_num += small_bags.size()/2 +1;
        }
        
    }

    cout << carrier_num;
    
    return 0;
}