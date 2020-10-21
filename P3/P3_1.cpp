#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Bag
{
    public:
    int weight;
    int isRegistered = 0;
    
    Bag(int weight)
    {
        this->weight = weight;
        this->isRegistered = 0;
    }
};

int main()
{
    int n = 1;
    int weight;
    int carrier_num = 0;
    int var;
    vector<Bag> bags;
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
            bags.push_back(Bag(weight));
        }
       
    }

    int bag_num = bags.size();
    int temp_sum, sum = 0, left_idx, right_idx;
    for(int i = 0; i < bag_num-1; i++)
    {
        if(bags[i].isRegistered == 1)
            continue;
        for(int j = i+1; j < bag_num; j++)
        {
            if(bags[j].isRegistered == 1)
                continue;
            temp_sum = bags[i].weight + bags[j].weight;
            if(temp_sum <= n && temp_sum > sum)
            {
                sum = temp_sum;
                left_idx = i;
                right_idx = j;
            }
            else if(bags[i].weight == n)
            {
                carrier_num++;
                bags[i].isRegistered = 1;
                break;
            }
        }
        if(sum > 0)
        {
            bags[left_idx].isRegistered = 1;
            bags[right_idx].isRegistered = 1;
            carrier_num++;
        }
        sum = 0;
    }
    for(int i = 0; i < bags.size(); i++)
    {
        if(bags[i].isRegistered != 1)
            carrier_num++;
    }
    
    cout << carrier_num;
    
    return 0;
}