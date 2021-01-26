#include <bits/stdc++.h> 
using namespace std; 
#define N 500 
long long dp[N][N]; 
bool v[N][N]; 
long long minMergeCost(int i, int j, long long* arr) { 
	if (i == j) 
		return 0; 
	if (v[i][j]) 
		return dp[i][j]; 
	v[i][j] = 1; 
	long long& x = dp[i][j]; 
	x = INT_MAX; 
	int tot = 0; 
	for (int k = i; k <= j; k++) 
		tot += arr[k]; 
	for (int k = i + 1; k <= j; k++) { 
		x = min(x, tot + minMergeCost(i, k - 1, arr) 
					+ minMergeCost(k, j, arr)); 
	} 
	return x; 
} 


int main() {
  int n;
  scanf("%d",&n);
  long long *totalArr = new long long[n];
  for(int i = 0; i < n; i++)
    scanf("%lld",&totalArr[i]);
  printf("%lld", minMergeCost(0, n - 1, totalArr));
}