#include <iostream>
using namespace std;
const int MAX = 2000000002;
int f_num, g_num, p, q;
int cnt1 = 0, cnt2 = 0;
long long ans = 0;
pair<int,int> *f;
pair<int,int> *g;
void initialize(){
  if(p < f[cnt1].first && p < g[cnt2].first)
  {
    if(f[cnt1].first < g[cnt2].first) p = f[cnt1].first;
    else p = g[cnt2].first;
  }
  else
  {
    while (cnt1 + 1 < f_num)
    {
      if ((f[cnt1].first <= p && p < f[cnt1 + 1].first) || p < f[cnt1].first)
          break;
      else
          cnt1++;
    }
    while(cnt2 + 1 < g_num)
    {
      if ((g[cnt2].first <= p && p < g[cnt2 + 1].first) || p < g[cnt2].first)
          break;
      else
          cnt2++;
    }
  }
}
void find()
{
  initialize();
  int temp1, temp2;
  long long tempY = 0, fY = 0, gY = 0, countX = p;
  while(countX <= q)
  {
    if(countX >= f[cnt1].first) fY = f[cnt1].second;
    if(countX >= g[cnt2].first) gY = g[cnt2].second;
    if(fY > gY) 
    {
      ans+= ((fY - tempY) % 10007) * ((q - countX + 1) % 10007);
      tempY = fY;
      if(cnt1 <= f_num)
      {
        cnt1++;
        if(g[cnt2].first <= countX) cnt2++; 
        if(f[cnt1].first > g[cnt2].first)
        {
          countX=g[cnt2].first;
        }
        else countX = f[cnt1].first;
      }
    }
    else
    {
      ans+= ((gY - tempY) % 10007) * ((q - countX + 1) % 10007);
      tempY = gY;
      if(cnt2 <= g_num)
      {
        cnt2++;
        if(f[cnt1].first <= countX) cnt1++; 
        if(g[cnt2].first > f[cnt1].first) countX=f[cnt1].first;
        else countX = g[cnt2].first;
      }
    }
  }
}
int main()
{
  cin >> f_num;
  f = new pair<int,int>[f_num+1];
  for (int i = 0; i < f_num; i++)
  {
      int a, b;
      cin >> a >> b;
      f[i].first = a; f[i].second = b;
  }
  f[f_num].first = MAX; f[f_num].second = f[f_num].second;
  cin >> g_num;
  g = new pair<int,int>[g_num+1];
  for (int i = 0; i < g_num; i++)
  {
      int a, b;
      cin >> a >> b;
      g[i].first = a; g[i].second = b;
  }
  g[g_num].first = MAX; g[g_num].second = g[g_num].second;
  cin >> p >> q;
  find();
  cout << ans%10007;
  return 0;
}