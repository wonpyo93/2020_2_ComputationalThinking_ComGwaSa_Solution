#include <iostream>
#include <algorithm>
using namespace std;
int n, index, b;
pair<int,int> *arr;
pair<int,int> *colorNum;
int *color;
void lookup(int a, int toColor) {
  long long xDif = 0, yDif = 0, dist = 0;
  b = a+1;
  if(color[a] == 1) colorNum[index].first++;
  else colorNum[index].second++;
  while(b < n) {
    if(color[b] == 0 || color[b] == -1) {
      xDif = arr[b].first - arr[a].first;
      yDif = arr[b].second - arr[a].second;
      dist = (xDif*xDif) + (yDif*yDif);
      if(xDif > 5) break;
      if(dist <= 25) color[b] = toColor;
      else color[b] = -1;  
    }
    b++;
  }
}
int main() {
  int answer = 0;
  scanf("%d",&n);
  arr = new pair<int,int>[n];
  colorNum = new pair<int,int>[n];
  for(int i = 0; i < n; i++)
    colorNum[i] = make_pair(0,0);
  color = new int[n]{0};
  for(int i = 0; i < n; i++)
    scanf("%d %d",&arr[i].first, &arr[i].second);
  sort(arr, arr + n);
  color[0] = 1;
  for(int i = 0; i < n; i++) {
    if(color[i] == 1)
      lookup(i, 2);
    else if(color[i] == 2)
      lookup(i, 1);
    else if(color[i] == -1 || color[i] == 0) {
      index++;
      color[i] = 1;
      lookup(i, 2);
    }
  }
  for(int i = 0; i < index+1; i++) {
    if(colorNum[i].second < colorNum[i].first)
      answer += colorNum[i].second;
    else
      answer += colorNum[i].first;
  }
  printf("%d",answer);
}