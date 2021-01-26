#include <vector>
#include <stdio.h>
using namespace std; 

const int N = 10001;
const int M = 100001;
vector <int> graph[N];
int color[N];
int parent[N];
bool detected;
int answer;

void dfs_cycle(int begin, int end) {
  if(color[end] == 2)
    return;
  if(color[end] == 1) {
      int temp = begin;
      int count = 0;
      while(temp != end) {
          temp = parent[temp];
          count++;
      }
      if(count % 2 == 0)
          detected = true;
      return;
  }
  color[end] = 1;
  parent[end] = begin;
  for(int v : graph[end]){
    if(v == parent[end])
      continue;   
    dfs_cycle(end,v);    
  }
  color[end] = 2;
}

void addEdge(int a, int b) {
  graph[a].push_back(b);
  graph[b].push_back(a);
}

void removeEdge(int a, int b) {
  graph[a].pop_back();
  graph[b].pop_back();
}

void binarySeek(int left, int right, int n, int *u, int *v) {
  detected = false;
  int mid = (left + right) / 2;  
  for(int i = mid + 1; i < right + 1; i++)
    removeEdge(u[i], v[i]);
  while(left <= right) {
    for(int j = 0; j < n + 1; j++) {
      color[j] = 0;
      parent[j] = 0;
    }
    for(int j = 1; j < n + 1; j++)
      if(color[j] == 0)
        dfs_cycle(0,j);
    if(detected == true) {
      answer = mid;
      detected = false;
      right = mid - 1;
      mid = (left + right)/2;
      for(int i = mid + 1; i < right + 2; i++)
        removeEdge(u[i], v[i]);
    }
    else {
      left = mid + 1;
      mid = (left + right)/2; 
      for(int i = left; i < mid + 1; i++)
        addEdge(u[i], v[i]);
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int *u = new int[m+1], *v = new int[m+1];
  detected = false;
  for(int i = 1 ; i < m + 1 ; i++) {
    scanf("%d %d", &u[i], &v[i]);
    addEdge(u[i], v[i]);
    if(detected == false && ((i & (i-1)) == 0 || (i == m))) {
      for(int j = 0; j < n + 1; j++){
          color[j] = 0;
          parent[j] = 0;
      }
      for(int j = 1; j < n + 1; j++)
        if(color[j] == 0)
          dfs_cycle(0,j);
      if(detected == true) {
          answer = i;
          binarySeek(i/2 + 1, i, n, u, v);
          detected = true;
      }
    }
  }
  printf("%d",answer);
}