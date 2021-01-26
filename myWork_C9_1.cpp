#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
  int n, a, b, max = -1, answer = 0;
  scanf("%d",&n);
  vector<pair<int, int>> arr;
  for(int i = 0; i < n; i++) {
    scanf("%d %d", &a, &b);
    arr.push_back(make_pair(a,b));
  }
  sort(arr.begin(), arr.end());
  int j = 1;
  while(j != n) {
    bool flag = false;
    pair<int,int> temp = arr[j-1];
    int temp_x = temp.first, temp_y = temp.second;
    for(int i = j; i < n; i++) {
      if(temp.first < arr[i].first && arr[i].second < temp.second) {
        temp.first = temp_x;
        temp.second = temp_y;
        j = i+1;
        flag = true;
      }
      else {
        if(arr[i].second > temp_y) {
          temp_y = arr[i].second;
          temp_x = arr[i].first;
        }
      }
    }
    if(flag == false) j++;
    answer++;
  }
  printf("%d",answer);
}