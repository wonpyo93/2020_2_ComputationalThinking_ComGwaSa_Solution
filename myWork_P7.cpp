#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

long long function(vector<long long> arr, int size) {
  long long sum_1 = 0, sum_2 = 0, l_sum = 0, diff = 0, temp = 0, diffInd=0, diffInd_2 = -1;
  if(size <= 1) return 0;
  if(size == 2) {
    for(int i = 0; i < size; i++)
      sum_1 += arr[i];
    return sum_1;
  }
  for(int i = 0; i < size; i++) 
    sum_1 += arr[i];
  diff = sum_1;
  sum_2 = sum_1;
  for(int i = 0; i < size; i++) {
    l_sum += arr[i];
    temp = abs(sum_1 - l_sum - l_sum);
    if(temp < diff) {
      diffInd_2 = -1;
      diff = temp;
      diffInd = i+1;
    }
    else if(temp == diff) {
      diffInd_2 = i+1;
    }
  }
  vector<long long> l_arr(arr.begin(), arr.begin() + diffInd);
  vector<long long> r_arr(arr.begin() + diffInd, arr.end());
  sum_1 += function(l_arr, diffInd);
  sum_1 += function(r_arr, size-diffInd);
  if(diffInd_2 != -1) {

    vector<long long> l_arr_2(arr.begin(), arr.begin() + diffInd_2);
    vector<long long> r_arr_2(arr.begin() + diffInd_2, arr.end());

    sum_2 += function(l_arr_2, diffInd_2);
    sum_2 += function(r_arr_2, size-diffInd_2);
  }
  else
    sum_2 = sum_1+1;
  if(sum_1 > sum_2)
    return sum_2;
  else
    return sum_1;
}

int main() {
  int n;
  scanf("%d",&n);
  vector<long long> totalArr(n);
  for(int i = 0; i < n; i++)
    scanf("%lld",&totalArr[i]);
  printf("%lld",function(totalArr, n));
}