#include <iostream>
#include <stdio.h>
using namespace std;
int* inputArray;
int input1;
int answer;
int input2;
int counterBottom;
int main() 
{
  counterBottom=0;
  answer = 0;
  cin >> input1;
  inputArray = new int[input1+1] {0};
  while(cin >> input2)  {
    if(input2==input1) answer++;
    else if(inputArray[input1 - input2] > 0) {
      inputArray[input1-input2]--;
      answer++;
    }
    else inputArray[input2]++;
  }
  for(int i = input1; i > input1 / 2; i--)  {
    if(inputArray[i] == 0) counterBottom+=inputArray[input1-i];
    else
    {
      answer+=inputArray[i];
      if(inputArray[i] >= counterBottom) counterBottom = 0;
      else counterBottom -= inputArray[i];
    }
  }
  answer += counterBottom/2 + counterBottom%2;
  cout << answer;
}