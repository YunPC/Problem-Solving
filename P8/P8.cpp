#include <iostream>
#include <cstring>

using namespace std;

int job[100001];

bool isMaximumMin(int mid, int n, int d)
{

    int late = 1;
    int complete[100001];
    for(int i = 1; i <= n; i++)
        complete[i] = 0;
    for(int i = 1; i <= n; i++)
    {
        //check remain task        
        if(late+d < i)
            return false;
        for(int j = 0; j < mid; j++)
        {
            if(job[late] > complete[late])
            {
                complete[late]++;
            }
            else // job == complete
            {
                if(late < i)
                {
                    late++;
                    j--;
                }
                else // late == i 할일까지 다 끝남
                {
                    break;
                }
            }
        }
    }
    if(late == n && job[late] == complete[late]) //late가 마지막 날이고 할일까지 다 끝냈으면
        return true;
    else
        return false;
    
    

}

int largestMinDist(int n, int d, int m)
{

	int res = 1000000000;


	int l = 1, r = m;

	while (l < r)
	{
		int mid = (l + r)/2;

		if (isMaximumMin(mid, n ,d))
		{
            r = mid;
			res = min(res, mid);
			
		}
		else
        {
            l = mid + 1;
        }
			
	}

	return res;
}

int main()
{
    int n, d, m, s;
    cin >> n >> d >> m;
    for(int i = 0 ; i < m; i++)
    {
        cin >> s;
        job[s] += 1;
    }

    int res;
    if(m == 1)
        cout << 1;
    else
    {
        res = largestMinDist(n, d, m);
        cout << res;    
    }
    // for(int i = 1; i <= m; i++)
    // {
    //     if(isMaximumMin(i, n, d))
    //     {
    //         cout << i;
    //         break;
    //     }
            
    // }
    
        

}