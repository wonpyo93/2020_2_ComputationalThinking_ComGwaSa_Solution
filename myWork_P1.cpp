#include <iostream>
#include <stdio.h>
using namespace std;

int theInput;
int counter;
int temp;
int digitCount;
int main() 
{
  counter = 0;
  digitCount = 1;
  cin >> theInput;
  while(theInput > 0)
  {
    temp = theInput % 10;
    if(temp > 3)
    {
      temp = temp - 1;
    }
    counter = counter + (temp * digitCount);
    digitCount = digitCount * 9;
    theInput = theInput / 10;
  }
  cout << counter;
  return 0;
}