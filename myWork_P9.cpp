#include <iostream>
using namespace std;
void merge(pair<long long,long long> list[], pair<long long,long long> sorted[], int left, int mid, int right) {
  int i, j, k, l;
  i = left;
  j = mid + 1;
  k = left;
  while(i <= mid && j <= right) {
    if(list[i].first <= list[j].first) {
      sorted[k].first = list[i].first;
      sorted[k++].second = list[i++].second;
    }
    else {
      sorted[k].first = list[j].first;
      sorted[k++].second = list[j++].second;
    }
  }
  if(i > mid) {
    for(l = j; l <= right; l++) {
      sorted[k].first = list[l].first;
      sorted[k++].second = list[l].second;
    }
  }
  else {
    for(l = i; l <= mid; l++) {
      sorted[k].first = list[l].first;
      sorted[k++].second = list[l].second;
    }
  }
  for(l = left; l <= right; l++) {
    list[l].first = sorted[l].first;
    list[l].second = sorted[l].second;
  }
}
void merge_sort(pair<long long,long long> list[], pair<long long,long long> sorted[], int left, int right) {
  int mid;
  if(left<right) {
    mid = (left+right)/2;
    merge_sort(list, sorted, left, mid);
    merge_sort(list, sorted, mid+1, right);
    merge(list, sorted, left, mid, right);
  }
}
int main() {
  int n, t;
  long long ans_total = 1, max;
  scanf("%d %d",&n, &t);
  pair<long long, long long> *arr = new pair<long long, long long>[n];
  pair<long long, long long> *sorted = new pair<long long,long long>[n];
  for(int i = 0; i < n; i++)
    scanf("%lld %lld",&arr[i].first, &arr[i].second);
  merge_sort(arr, sorted, 0, n-1);
  if(n != 1) {
    max = sorted[n-1].first + (sorted[n-1].second * t);
    for(int i = n-2; i >= 0; i--) {
      long long temp = sorted[i].first + (sorted[i].second * t);
      if(temp < max) {
        max = temp;
        ans_total++;
      }
    }
  }
  printf("%lld", ans_total);
}