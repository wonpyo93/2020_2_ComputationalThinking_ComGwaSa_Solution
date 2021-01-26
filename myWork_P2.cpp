#include <iostream>
#include <stdio.h>
using namespace std;

int chosen;
int challenger;
int input1, input2;
int *newLocation, *newPeople;
int *oldLocation, *oldPeople;
void merge(int left, int right)
{
	int mid = (left + right) / 2;
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right)
	{
		if (oldLocation[i] <= oldLocation[j]) 
    {
			newLocation[k++] = oldLocation[i++]; 
			newPeople[k-1] = oldPeople[i-1]; 
    }
		else
    {
			newLocation[k++] = oldLocation[j++];
      newPeople[k-1] = oldPeople[j-1];
    }
	}
	int tmp = i>mid ? j : i;
	while(k<=right)
  {
    newLocation[k++] = oldLocation[tmp++];
    newPeople[k-1] = oldPeople[tmp-1];
  }
	for (int i=left;i<=right;i++)
  {
    oldLocation[i] = newLocation[i];
    oldPeople[i] = newPeople[i];
  }
}

void partition(int left,int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2; 
		partition(left, mid);
		partition(mid + 1, right);
		merge(left, right);
	}
}

int main() 
{
 cin >> input1 >> input2;
 oldLocation = new int[input1];
 oldPeople = new int[input1];
 newLocation = new int[input1];
 newPeople = new int[input1];
 chosen = 0;
 for(int i = 0; i < input1; i++)
 {
   cin >> oldPeople[i] >> oldLocation[i];
 }
 partition(0, input1 - 1);
 challenger = 0;
 int theCounter = 0;
 while(true)
 {
   chosen = chosen + newPeople[theCounter];
   theCounter++;
   if((newLocation[theCounter] >  newLocation[0] + input2 + input2) || theCounter >= input1)
   {
      break;
   }
 }
 challenger = chosen;
 for(int i = 1; i < input1; i++)
 {
   challenger = challenger - newPeople[i-1];
   while((newLocation[theCounter] <= newLocation[i] + input2 + input2) && theCounter < input1)
   {
     challenger += newPeople[theCounter];
     theCounter++;
   }
   if(challenger > chosen)
   {
      chosen = challenger;
   }
 }

 cout << chosen;
}