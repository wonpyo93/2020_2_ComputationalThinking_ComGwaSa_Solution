#include <stdio.h>
#include <iostream>
using namespace std;
int n, d, m;
int k=1;

int find(int* s){
  int *arr;
  bool flag = false;
  while(1) {
    int leftover;
    arr = new int[d+1];
    flag = false;
    for(int day=1; day<=n; day++) {
      int k_temp = k;
      leftover=0;
      arr[0] = s[day];
      for(int i = d; i >= 0; i--) {
        if(k_temp > arr[i]) {
          k_temp = k_temp - arr[i];
          arr[i] = 0;
        }
        else {
          arr[i] = arr[i] - k_temp;
          k_temp = 0;
          break;
        }
      }
      if(arr[d] > 0) {
        break;
      }
      else {
        for(int i = d; i > 0; i--) {
          arr[i] = arr[i-1];
          leftover += arr[i];
        }
        arr[0] = 0;
        if(day == n) flag = true;
      }
    }
    if(flag == false || leftover > 0) k++;
    else return k;
  }
}
int main(void) {
  cin >> n >> d >> m;
  int *s = new int[100001];
  for (int i = 1; i <= m; i++)
  {
      int tmp;
      cin >> tmp;
      s[tmp]++;
  }
  k = find(s);
  printf("%d",k);
}