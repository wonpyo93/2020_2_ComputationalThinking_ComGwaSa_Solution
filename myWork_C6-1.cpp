#include <stdio.h>
#include <vector>
using namespace std;
int findByBs(vector<pair<int,int>> t, int size, int val) {
  int low = 0, high = size-1;
  if(val <= t[0].second)
    return -1;
  if(val > t[high].second)
    return size;
  while(low <= high) {
    int mid = (low + high) / 2;
    if(low == high)
      return low;
    else {
      if(t[mid].second == val)
        return mid-1;
      if(t[mid].second < val) {
        low = mid + 1;
        if(t[low].second >= val) return mid;
      }
      else
        high = mid - 1;
    }
  }
  return -1;
}
int* lisArr(int arr[], int size) {
  vector<pair<int,int>> t;
  t.push_back(make_pair(-1,-1));
  int end = 0;
  int *lis = new int[size];
  lis[0] = 0;
  for(int i = 0; i < size; i++) {
    int index = findByBs(t, t.size(), arr[i]);
    if(index == t.size()) {
      int toPush = t[t.size()-1].first + 1;
      t.push_back(make_pair(toPush, arr[i]));
      lis[i] = toPush;
    }
    else {
      lis[i] = t[index].first+1;
      if(t[index+1].second > arr[i])
        t[index+1].second = arr[i];
    }
  }
  return lis;
}
int* ldsArr(int arr[], int size) {
  int *t = new int[size];
  for(int i = 0; i < size; i ++) {
    t[i] = arr[size-i-1];
  }
  int *lds = lisArr(t, size);
  for(int i = 0; i < size; i ++) {
    t[i] = lds[size-i-1];
  }
  return t;
}
int main() { 
  int n, answer = 0;
  scanf("%d", &n);
  int *seq = new int[n];
  for(int i = 0; i < n; i++)
    scanf("%d",&seq[i]);
	int *lis = lisArr(seq, n), *lds = ldsArr(seq, n);
  for(int i = 0; i < n; i++)
    if(answer < lis[i] + lds[i])
      answer = lis[i] + lds[i];
  printf("%d",answer+1);
	return 0; 
} 
