#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> g[50001];
int bfs(int start, bool* visited) {
  int r = 0, b = 0;
  visited[start] = true;
  int start_color = 0;
  queue<pair<int,int>> q;
  q.push(make_pair(start, start_color));
  while(!q.empty()) {
    pair<int,int> node = q.front();
    q.pop();
    if(node.second == 0)
      r++;
    else
      b++;
    for(int i=0;i<g[node.first].size();i++){
      int next = g[node.first][i];
      if(visited[next])
        continue;
      visited[next] = true;
      int next_color = node.second == 0 ? 1 : 0;
      q.push(make_pair(next, next_color));
    }
  }
  return r < b ? r : b;
}
int binary_search(vector<pair<int, int>>* v, pair<int, int>* p) {
  int l = 0, r = v->size();
  while(l + 1 < r) {
    int mid = (l + r) / 2;
    if((*v)[mid].first < p->first)
      l = mid;
    else if((*v)[mid].first > p->first)
      r = mid;
    else {
      if((*v)[mid].second < p->second)
        l = mid;
      else if((*v)[mid].second > p->second)
        r = mid;
      else
        return mid;
    }
  }
  return l;
}
int main() {
  int dy1[] = {1,-4,-4,-4,-3,0}, dy2[] = {5,4,4,4,3,0};
  int n, a, b, answer = 0, temp;
  scanf("%d", &n);
  vector<pair<int,int>> arr;
  for(int i = 0; i < n; i++) {
    scanf("%d %d",&a, &b);
    arr.push_back(make_pair(a,b));
  }
  sort(arr.begin(), arr.end());
  for(int i = 0; i < n; i++) {
    pair<int, int> p = arr[i];
    for(int j = 0; j < 6; j++) {
      int xBound = p.first + j, yLow = p.second + dy1[j], yHigh = p.second + dy2[j];
      pair<int, int> upper_bound = make_pair(xBound, yHigh);
      temp = binary_search(&arr, &upper_bound);
      for(int k = temp; arr[k].first == xBound && arr[k].second >= yLow && arr[k].second <= yHigh; k--) {
        g[i].push_back(k);
        g[k].push_back(i);
      }
    }
  }
  bool* visited = new bool[n];
  for(int i = 0; i < n; i++)
    visited[i] = false;
  for(int i=0;i<n;i++) {
    if(visited[i])
      continue;
    answer += bfs(i, visited);
  }
  printf("%d",answer);
}