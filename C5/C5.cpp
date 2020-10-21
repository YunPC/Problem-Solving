#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

struct Ballon
{
    float r;
    int pos;
    int max_r;
};

Ballon ballons[100000];
int main()
{
    int n, pos, max_r, comp_idx = 0;
    double temp_r, init_r;
    double res_r;
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> pos >> max_r;
        ballons[i].pos = pos;
        ballons[i].max_r = max_r;
    }

    cout << fixed;
    cout.precision(3);

    ballons[0].r = ballons[0].max_r;
    res_r = (double)ballons[0].max_r;
    cout << res_r << '\n';

    for (int i = 1; i < n; i++)
    {   
        init_r = ballons[i].max_r;
        
        if(ballons[comp_idx].pos + ballons[comp_idx].r > ballons[i].pos - ballons[i].max_r)
        {
            temp_r = pow((ballons[i].pos - ballons[comp_idx].pos), 2) / (4*ballons[comp_idx].r);
            init_r = min(temp_r, init_r);
            double comp_right = ballons[comp_idx].pos + ballons[comp_idx].r;
            double i_right = ballons[i].pos + init_r;
            if(comp_right < i_right)
                comp_idx = i;
            if(comp_idx != i-1)
            {
                temp_r = pow((ballons[i].pos - ballons[i-1].pos), 2) / (4*ballons[i-1].r);
                init_r = min(temp_r, init_r);
            }
            
        }
        cout << floor(init_r*1000)/1000 << '\n';
        ballons[i].r = floor(init_r*1000)/1000;
    }
}