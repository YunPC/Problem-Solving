#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool desc(int i, int j)
{
    return j < i;
}
int main()
{
    int n = 1;
    int carrier_num = 0;
    int var;
    bool isfirst = true;
    vector<int>bags;
    
    
    
    while (scanf("%d", &var) != EOF)
    {
        if(isfirst)
        {
            n = var;
            isfirst = false;
        }
        else
        {
            if(var == n)
            {
                carrier_num++;
                continue;
            }
            bags.push_back(var);
            
        }
       
    }
    sort(bags.begin(), bags.end(), desc);

    while(!bags.empty())
    {
        if(bags.size() == 1)
        {
            carrier_num++;
            break;
        }
        if(bags.front() + bags.back() <= n)
        {
            bags.pop_back();
            bags.erase(bags.begin());
            carrier_num++;

        }
        else
        {
            carrier_num++;
            bags.erase(bags.begin());
        }
        
    }
    

    std::cout << carrier_num;
    
    return 0;
}
