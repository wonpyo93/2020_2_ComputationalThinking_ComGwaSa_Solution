#include <iostream>
#include <stdio.h>
using namespace std;
int *sorted;
void merge(int list[], int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;
  while(i<=mid && j<=right){
    if(list[i]<=list[j])
      sorted[k++] = list[i++];
    else
      sorted[k++] = list[j++];
  }
  if(i>mid){
    for(l=j; l<=right; l++)
      sorted[k++] = list[l];
  }
  else{
    for(l=i; l<=mid; l++)
      sorted[k++] = list[l];
  }
  for(l=left; l<=right; l++){
    list[l] = sorted[l];
  }
}
void merge_sort(int list[], int left, int right){
  int mid;
  if(left<right){
    mid = (left+right)/2;
    merge_sort(list, left, mid);
    merge_sort(list, mid+1, right);
    merge(list, left, mid, right);
  }
}
int main(){
  int n, k, nTemp;
  int *theArray;
  cin >> n >> k;
  nTemp = n;
  theArray = new int[n];
  sorted = new int[n];
  for(int i = 0; i < n; i++)
    cin >> theArray[i];
  merge_sort(theArray, 0, n-1);
  int ans, left = 1, right = sorted[n-1] - sorted[0];
  if(k == 2) ans = right;
  else
  {
    while(left <= right){
      int mid = (left + right) /2;
      int counter = 1, prev = sorted[0];
      for(int i = 1; i < n; i++)
      {
        if(sorted[i] - prev >= mid){
          prev = sorted[i];
          counter++;
          if(counter>=k) break;
        }
      }
      if(counter < k)
      {
        right = mid-1;
      }
      else
      {
        ans = mid;
        left = mid + 1;
      }
    }
  }
  cout << ans;
  return 0;
}