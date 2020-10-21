#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int hireCarrier(vector<int> big_bags, vector<int> small_bags, int n);

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

    carrier_num += hireCarrier(big_bags, small_bags, n);

    cout << carrier_num;
    
    return 0;
}

int hireCarrier(vector<int> big_bags, vector<int> small_bags, int n)
{
    if(small_bags.empty())
    {
        return big_bags.size();
    }
    else if(big_bags.empty())
    {
        if(small_bags.size() % 2 == 0)
            return small_bags.size()/2;
        else
        {
            return small_bags.size()/2 +1;
        }
    }
    else
    {
        if(big_bags.front() + small_bags.front() <= n)
        {
            big_bags.erase(big_bags.begin());
            small_bags.erase(small_bags.begin());
            return 1 + hireCarrier(big_bags, small_bags, n);
        }
        else if(big_bags.size() > 0)
        {
            big_bags.erase(big_bags.begin());
            return 1 + hireCarrier(big_bags, small_bags, n);
        }
    }
    
}