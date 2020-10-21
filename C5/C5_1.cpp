#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

struct Ballon
{
    double r;
    int pos;
    int max_r;
};

Ballon ballons[100000];

int main()
{
    int n, pos;
    double max_r, res_r, comp_r;
    stack<Ballon> check_stack;
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> pos >> max_r;
        ballons[i].pos = pos;
        ballons[i].max_r = max_r;
    }

     cout << fixed;
     cout.precision(6);

    ballons[0].r = ballons[0].max_r;
    res_r = ballons[0].max_r;
    check_stack.push(ballons[0]);

    cout << res_r << endl;

    for(int i = 1; i < n; i++)
    {
        res_r = ballons[i].max_r;
        //checking
        while(!check_stack.empty())
        {
            comp_r = (pow(ballons[i].pos - check_stack.top().pos, 2)) / (4*check_stack.top().r);
            if(comp_r < res_r)
            {
                res_r = comp_r;
                if(res_r > check_stack.top().r)
                {
                    check_stack.pop();
                }
            }
            else
            {
                if(res_r > check_stack.top().r)
                {
                    check_stack.pop();
                }
                else
                {
                    break;
                }
            }
            
        }
        //push
        ballons[i].r = res_r;
        cout << res_r << endl;
        check_stack.push(ballons[i]);
    }

}