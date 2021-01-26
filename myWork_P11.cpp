#include <iostream> 
#include <cstring>
using namespace std;
int g[1000][1000];
int main() { 
  int n;
  scanf("%d", &n);
  pair<int,int> *arr = new pair<int,int>[n];
  string *input = new string[n];
  for(int i = 0; i < n; i++)
    cin >> input[i];
  for(int i = 0; i < n; i++) {
    arr[i].first = input[i].front();
    arr[i].second = input[i].back();
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i != j) {
        if(arr[i].second == arr[j].first) {
          g[i][j] = 1;
        }
      }
    }
  }
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      printf("%d ", g[i][j]);
    }
    printf("\n");
  }
  bool *visited = new bool[n];
  memset(visited, false, n);
  for(int i = 0; i < n; i++)
    printf("%d ",visited[i]);
  printf("\n");
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      
    }
  }
	return 0; 
}