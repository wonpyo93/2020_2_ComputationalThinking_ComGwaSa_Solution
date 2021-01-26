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
  vector<int> stack;
  sort(arr.begin(), arr.end());
  while(arr.size() != 0) {
    stack.clear();
    pair<int,int> temp = arr.front();
    int temp_x = temp.first, temp_y = temp.second;
    arr.erase(arr.begin());
    int size = arr.size();
    for(int i = 0; i < size; i++) {
      if(temp.first < arr[i].first && arr[i].second < temp.second) {
        int tempz = stack.size();
        for(int j = 0; j < tempz; j++) {
          arr.erase(arr.begin()+stack.back());
          stack.pop_back();
          i--;
          size--;
        }
        arr.erase(arr.begin()+i);
        size--;
        i--;
        temp.first = temp_x;
        temp.second = temp_y;
      }
      else {
        stack.push_back(i);
        if(arr[i].second > temp_y) {
          temp_y = arr[i].second;
          temp_x = arr[i].first;
        }
      }
    }
    answer++;
  }
  printf("%d",answer);
}