#include <iostream>
#include <cstring>

using namespace std;

int job[100001];

bool isMaximumMin(int mid, int n, int d)
{
	int task = job[1];

	for (int i=2; i<=n-d; i++)
	{
		task -= mid;
        task += job[i];
	}

    if(task > d)
        return false;
    else
        return true;
    

	return 0;
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
    
        

}