#include <bits/stdc++.h>

using namespace std;
int poles[100000];

bool isMaximumMin(int mid, int n, int k)
{
	int pos = poles[0];

	int amplifier = 1;

	for (int i=1; i<n; i++)
	{
		if (poles[i] - pos >= mid)
		{

			pos = poles[i];
			amplifier++;

			if (amplifier == k)
			return true;
		}
	}
	return 0;
}


int largestMinDist(int n, int k)
{

	sort(poles,poles+n);


	int res = -1;


	int min_dist = 1, max_dist = poles[n-1];

	while (min_dist < max_dist)
	{
		int mid = (min_dist + max_dist)/2;

		if (isMaximumMin(mid, n, k))
		{
			res = max(res, mid);
			min_dist = mid + 1;
		}

		else
			max_dist = mid;
	}

	return res;
}

int main()
{
	int n, k;
    int pos;
    cin >> n >> k;
	for(int pole_idx = 0; pole_idx < n; pole_idx++)
    {
        cin >> pos;
        poles[pole_idx] = pos;
    }
	cout << largestMinDist(n, k);
	return 0;
}
