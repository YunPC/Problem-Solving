#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int main()
{
    int n, k;
    
    cin >> n >> k;
    int table[51][3];
    int hanoi[50];
    int disk_cnt, disk_num;
    for(int tower_num = 1; tower_num <= 3; tower_num++)
    {
        cin >> disk_cnt;
        for(int disk = 0; disk < disk_cnt; disk++)
        {
                cin >> disk_num;
                table[disk_num][0] = tower_num;
                table[disk_num][1] = 0;
                table[disk_num][2] = 0;

        }
    }
    int initial_tower = table[n][0];
    bool is_two_tower_empty = true;
    for(int disk = 1; disk <= n; disk++)
    {
        if(initial_tower != table[disk][0])
            is_two_tower_empty = false;
    }
    if(is_two_tower_empty && table[n][0] == k)
    {
        cout << 0;
        return 0;
    }
    table[n][1] = k;
    int source, destination, buffer;
    source = table[n][0];
        destination = table[n][1];
        if(source != destination)
        {
        switch (source + destination)
        {
        case 3:
            table[n][2] = 3;
            break;
        case 5:
            table[n][2] = 1;
        case 4:
            table[n][2] = 2;
        default:
            break;
        }
        }
        else
        {
            table[n][2] = source;
        }
        
    buffer = table[n][2];
    for(int idx = n-1; idx >= 1; idx--)
    {
        table[idx][1] = buffer;
        source = table[idx][0];
        destination = table[idx][1];
        if(source != destination)
        {
        switch (source + destination)
        {
        case 3:
            table[idx][2] = 3;
            break;
        case 5:
            table[idx][2] = 1;
            break;
        case 4:
            table[idx][2] = 2;
        default:
            break;
        }
        }
        else
        {
            table[idx][2] = source;
        }
        buffer = table[idx][2];

    }
    int moving_cnt = 0;
    for(int disk_num = 1; disk_num <= n; disk_num++)
    {
        destination = table[disk_num][1];
        buffer = table[disk_num][2];

        if(destination == buffer)
        {
           continue;
        }
        else
        {
            moving_cnt += pow(2, disk_num-1);
        }
        
        }
        
    
       
    cout << moving_cnt;


    
    return 0;
}


