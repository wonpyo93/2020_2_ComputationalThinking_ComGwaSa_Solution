#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int *seq = new int[n], *r_dp = new int[n], *l_dp = new int[n];
  for(int i = 0; i < n; i++) {
    scanf("%d",&seq[i]);
  }
  for(int i = 0; i < n; i++) {
    r_dp[i] = 1;
    for(int j = 0; j < i; j++)
      if(seq[j] < seq[i] && r_dp[i] < r_dp[j] + 1)
        r_dp[i] = r_dp[j] + 1;
  }
  for(int i = n - 1; i >= 0; i--) {
    l_dp[i] = 1;
    for(int j = n - 1; j > i; j--)
      if(seq[j] < seq[i] && l_dp[i] < l_dp[j] + 1)
        l_dp[i] = l_dp[j] + 1;
  }
  int max = 0;
  for(int i = 0; i < n; i++) {
    if(max < r_dp[i] + l_dp[i])
      max = r_dp[i] + l_dp[i];
  }
  printf("%d",max - 1);
	return 0;
}