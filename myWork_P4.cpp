#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int rotatePeg(int pegLoc)
{
  if(pegLoc < 2) return pegLoc+1;
  else return 0;
}
int power(int p) {
  if (p == 0) return 1;
  if (p == 1) return 2;
  return 2 * power(p-1);
}
int main() {
  int pegLoc;
  int answer = 0;
  int N, destination;
  cin >> N >> destination;
  destination--;
  queue<int> *q1;
  q1 = new queue<int>[3];
  int tempCount;
  int numToPush;
  cin >> tempCount;
  for( int i=0; i < tempCount; i++){
    cin >> numToPush;
    q1[0].push(numToPush); 
  }
  cin >> tempCount;
  for( int i=0; i < tempCount; i++)
  {
    cin >> numToPush;
    q1[1].push(numToPush); 
  }
  cin >> tempCount;
  for( int i=0; i < tempCount; i++)
  {
    cin >> numToPush;
    q1[2].push(numToPush); 
  }
  while(N > 0)
  {
    if(q1[destination].front() == N)
    {
      q1[destination].pop();
      N--;
    }
    else
    {
      destination = rotatePeg(destination);
      if(q1[destination].front() == N)
      {
        q1[destination].pop();
        destination = rotatePeg(destination);
      }
      else
        q1[rotatePeg(destination)].pop();
      N--;
      answer += power(N);
    }
  }
  cout << answer;
}