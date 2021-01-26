#include <iostream>
using namespace std; 
const int MAX = 455;
int store[MAX], n; 
int graph[MAX][MAX];  
int weight[MAX];
int max_res;

bool is_clique(int b) { 
    int temp = 0;
    for (int i = 1; i < b; i++) { 
      temp += weight[store[i]];
      for (int j = i + 1; j < b; j++) 
        if (graph[store[i]][store[j]] == 0) 
          return false; 
    }
    max_res = max(max_res, temp);
    return true; 
}

int maxCliques(int i, int l) { 
  int max_ = 0; 
  for (int j = i + 1; j <= n; j++) { 
    store[l] = j; 
    if(is_clique(l + 1)) { 
      max_ = max(max_, l); 
      max_ = max(max_, maxCliques(j, l + 1)); 
    } 
  } 
  return max_; 
}

int main() {
  max_res = 0;
  int size, a, b;
  scanf("%d %d", &n, &size);
  for(int i = 0; i < n; i++) {
    scanf("%d", &weight[i+1]);
  }
  for(int i = 0; i < size; i++) {
    scanf("%d %d", &a, &b);
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
	int hi = maxCliques(0, 1); 
  cout << max_res;
	return 0; 
}
