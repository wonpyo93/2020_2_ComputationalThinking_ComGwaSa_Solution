#include <iostream>
using namespace std;
int main() {
  int n, t;
  long long ans_total = 1, max;
  scanf("%d %d",&n, &t);
  pair<long long, long long> *arr = new pair<long long, long long>[n];
  for(int i = 0; i < n; i++)
    scanf("%lld %lld",&arr[i].first, &arr[i].second);
  if(n != 1) {
    max = arr[n-1].first + (arr[n-1].second * t);
    for(int i = n-2; i >= 0; i--) {
      long long temp = arr[i].first + (arr[i].second * t);
      if(temp < max) {
        max = temp;
        ans_total++;
      }
    }
  }
  printf("%lld", ans_total);
}