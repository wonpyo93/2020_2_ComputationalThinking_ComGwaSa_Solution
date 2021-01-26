#include <iostream>
#include <stdio.h>
using namespace std;

int pause;
int input1;
int **inputArray;
int distanceArray[500][500] {0};
int theStart, theEnd;
int answer;
int checkDirection(int i, int j);

int checkLeft(int i, int j)
{
  int toReturn = -1;
  if(inputArray[i][j-1] < inputArray[i][j])
  {
    if(distanceArray[i][j-1] == 0)
    {
      int temp = checkDirection(i, j-1);
      if(temp == -1) temp = 0;
      toReturn = inputArray[i][j] - inputArray[i][j-1] + temp;
    }
    else
    {
      int temp = distanceArray[i][j-1];
      if(temp == -1) temp = 0;
      toReturn = inputArray[i][j] - inputArray[i][j-1] + temp;
    }
  }
  return toReturn;
}

int checkRight(int i , int j)
{
  int toReturn = -1;
  if(inputArray[i][j+1] < inputArray[i][j])
  {
    if(distanceArray[i][j+1] == 0)
    {
      int temp = checkDirection(i, j+1);
      if(temp == -1) temp = 0;
      toReturn = inputArray[i][j] - inputArray[i][j+1] + temp;
    }
    else
    {
      int temp = distanceArray[i][j+1];
      if(temp == -1) temp = 0;
      toReturn = inputArray[i][j] - inputArray[i][j+1] + temp;
    }
  }
  return toReturn;
}

int checkUp(int i , int j)
{
  int toReturn = -1;
  if(inputArray[i-1][j] < inputArray[i][j])
  {
    if(distanceArray[i-1][j] == 0)
    {
      int temp = checkDirection(i-1, j);
      if(temp == -1) temp = 0;
      toReturn = inputArray[i][j] - inputArray[i-1][j] + temp;
    }
    else
    {
      int temp = distanceArray[i-1][j];
      if(temp == -1) temp = 0;
      toReturn = inputArray[i][j] - inputArray[i-1][j] + temp;
    }
  }
  return toReturn;
}

int checkDown(int i , int j)
{
  int toReturn = -1;
  if(inputArray[i+1][j] < inputArray[i][j])
  {
    if(distanceArray[i+1][j] == 0)
    {
      int temp = checkDirection(i+1, j);
      if(temp == -1) temp = 0;
      toReturn = inputArray[i][j] - inputArray[i+1][j] + temp;
    }
    else
    {
      int temp = distanceArray[i+1][j];
      if(temp == -1) temp = 0;
      toReturn = inputArray[i][j] - inputArray[i+1][j] + temp;
    }
  }
  return toReturn;
}

int checkDirection(int i, int j)
{
  int answer = -1;
  int tempCheck = 0;
  if(distanceArray[i][j] == 0)
  {
    if(j > 0)
    {
      tempCheck = checkLeft(i, j);
      if(tempCheck > answer)
          answer = tempCheck;
    }
    if(j < input1 - 1)
    {
      tempCheck = checkRight(i, j);
      if(tempCheck > answer)
          answer = tempCheck;
    }
    if(i > 0)
    {
      tempCheck = checkUp(i, j);
      if(tempCheck > answer)
          answer = tempCheck;
    }
    if(i < input1 - 1)
    {
      tempCheck = checkDown(i, j);
      if(tempCheck > answer)
          answer = tempCheck;
    }
    distanceArray[i][j] = answer;
  }
  return distanceArray[i][j];
}

int main() 
{
  theStart = 1;
  theEnd = 0;
  answer = 0;
  cin >> input1;
  inputArray = new int*[input1];
  for(int i = 0; i < input1; i++)
      inputArray[i] = new int[input1];

  for(int i = 0; i < input1; i++)
  {
    for(int j = 0; j < input1; j++)
    {
      cin >> inputArray[i][j];
    }
  }
  int temp;
  for(int i = 0; i < input1; i++)
  {
    for(int j = 0; j < input1; j++)
    {
      temp = checkDirection(i, j);
      if(temp > answer)
          answer = temp;
    }
  }
  cout << answer;
}