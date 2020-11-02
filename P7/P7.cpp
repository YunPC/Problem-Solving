#include <iostream>
#include <limits>
using namespace std; 

#define N 500 

int cost[N][N]; 
bool v[N][N]; 

int getMinTime(int i, int j, int* arr) 
{ 
	if (i == j) 
		return 0; 

	if (v[i][j]) 
		return cost[i][j]; 

	v[i][j] = 1; 
	int& res = cost[i][j]; 

	res = 1000000000; 

	int total = 0; 
	for (int k = i; k <= j; k++) 
		total += arr[k]; 

	for (int k = i + 1; k <= j; k++) { 
		res = min(res, total + getMinTime(i, k - 1, arr) 
					+ getMinTime(k, j, arr)); 
	} 

	return res; 
} 

// Driver code 
int main() 
{ 
	int arr[500]; 
	int n, card_num; 
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> card_num;
		arr[i] = card_num;
	}
	cout << getMinTime(0, n - 1, arr); 

	return 0; 
} 
