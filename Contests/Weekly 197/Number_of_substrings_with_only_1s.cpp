#include <iostream>
#include <string>
#include <cmath>
using namespace std;
void series(int n, long long *r) //recursion
{
  if(n == 1)
  {
    *r += 1;
  }
  else
  {
    *r += n;
    series(n-1, r);
  }
}
/*

int x = 0;
for(int i = n; i > 0; i--)
{
  x += i;
}
return x;
*/ //For Loop instead of recursion
int subsetsOf1(string s)
{
  int cnt = 0;
  int subsets = 0;
  for(int i = 0; i < s.length(); i++)
  {
    if(s[i] == '1')
    {
      cnt++;
    }
    else if(cnt != 0)
    {
      long long localSS = 0;
      series(cnt, &localSS);
      subsets += localSS % (long long)(pow(10,9) + 7);
      cnt = 0;
    }
  }
  if(cnt != 0)
  {
    long long localSS = 0;
    series(cnt, &localSS);
    subsets += localSS % (long long)(pow(10,9) + 7);
  }
  return subsets;
}
int main()
{
  string s;
  cin >> s;
  int cnt = subsetsOf1(s);
  cout << "The result is: " << cnt;
}
//1 -> 1, 2 -> 3, 3 -> 6, 4 -> 10, 5 -> 15, 6 -> 21
//General term = last term + cnt;
