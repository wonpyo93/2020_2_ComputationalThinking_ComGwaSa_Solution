#include <iostream>
#include <math.h>
using namespace std;
int main() {
  int toCheck= 0;
  int n;
  scanf("%d",&n);
  pair<int,double> *thePair = new pair<int,double>[n];
  for(int i = 0; i < n; i++) {
    scanf("%d %lf",&thePair[i].first,&thePair[i].second);
    if(i>0) {
      for(int j = toCheck; j < i; j++) {
        double fTemp = pow(thePair[i].first - thePair[j].first, 2)/(4*thePair[j].second);
        if(thePair[i].second >= fTemp)
          thePair[i].second = fTemp;
      }
      if(thePair[i].second > thePair[toCheck].second)
        toCheck = i;
    }
  }
  for( int i = 0; i < n; i++)
    printf("%.3f\n",thePair[i].second);
  return 0;
}