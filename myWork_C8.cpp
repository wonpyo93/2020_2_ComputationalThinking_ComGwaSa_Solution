#include <iostream>
#include <math.h>
using namespace std;
void merge(pair<float,float> list[], pair<float,float> sorted[], int left, int mid, int right) {
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
void merge_sort(pair<float,float> list[], pair<float,float> sorted[], int left, int right) {
  int mid;
  if(left<right) {
    mid = (left+right)/2;
    merge_sort(list, sorted, left, mid);
    merge_sort(list, sorted, mid+1, right);
    merge(list, sorted, left, mid, right);
  }
}
int main() {
  int n, d, dSquare, answer = 0;
  scanf("%d %d", &n, &d);
  if(n != 0) {
    dSquare = d * d;
    pair<float, float> *arr = new pair<float,float>[n];
    pair<float, float> *sorted = new pair<float,float>[n];
    for(int i = 0; i < n; i++)
      scanf("%f %f", &arr[i].first, &arr[i].second);
    for(int i = 0; i < n; i++) {
      float deviation = sqrt(dSquare - (arr[i].second*arr[i].second));
      float x = arr[i].first;
      arr[i].first = x - deviation;
      arr[i].second = x + deviation;
    }
    merge_sort(arr, sorted, 0, n-1);
    float end = sorted[0].second;
    answer++;
    for(int i = 1; i < n; i++) {
      if(sorted[i].first <= end && sorted[i].second <= end) {
        end = sorted[i].second;
      }
      else if(sorted[i].first > end) {
        answer++;
        end = sorted[i].second;
      }
    }
  }
  printf("%d",answer);
}