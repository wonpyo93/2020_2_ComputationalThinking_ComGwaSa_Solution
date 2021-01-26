#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
void fillDistance(int root, int N, int* theArray, queue<int> *theQ){
  int counter = 0;
  queue<int> goThrough;
  goThrough.push(root);
  int temp1, temp2, temp3;
  while(!goThrough.empty()){
    temp1 = goThrough.front();
    goThrough.pop();
    temp2 = theQ[temp1].size();
    for(int i = 0; i < temp2; i++){
      temp3 = theQ[temp1].front();
      theQ[temp1].pop();
      if(theArray[temp3] == 0 && temp3 != root){
        theArray[temp3]= theArray[temp1]+1;
        goThrough.push(temp3);
      }
    }
  }
} 
void addToGraph(int a, int b, queue<int> *q1, queue<int> *q2, queue<int> *q3){
  q1[a].push(b);
  q1[b].push(a);
	q2[a].push(b);
  q2[b].push(a);
	q3[a].push(b);
  q3[b].push(a);
}


int main() {
  queue<int> * q1;
  queue<int> * q2;
  queue<int> * q3;
  int p, q, r, N, M;
  int input1, input2;
  int answer;
  cin >> p >> q >> r >> N >> M;
  q1 = new queue<int>[N];
  q2 = new queue<int>[N];
  q3 = new queue<int>[N];
  for(int i = 0; i < M; i++){
    cin >> input1 >> input2;
    addToGraph(input1-1, input2-1, q1, q2, q3);
  }
  int *arrayForOne = new int[N] {0};
  fillDistance(0, N, arrayForOne, q1);
  int *arrayForTwo = new int[N] {0};
  fillDistance(1, N, arrayForTwo, q2);
  int *arrayForLast = new int[N] {0};
  fillDistance(N-1, N, arrayForLast, q3);
  answer = (arrayForOne[N-1] * p) + (arrayForTwo[N-1] * q);
  for(int i = 0; i < N; i++)
    if(((arrayForOne[i] * p) + (arrayForTwo[i] * q) + (arrayForLast[i] * r)) < answer)
        answer = (arrayForOne[i] * p) + (arrayForTwo[i] * q) + (arrayForLast[i] * r);
  cout << answer;
  return 0;
}