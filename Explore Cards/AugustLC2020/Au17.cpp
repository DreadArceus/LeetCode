//+1 problem, dont know why...
#include <iostream>
#include <vector>
using namespace std;
vector<int> solve(int n, int c)
{
  vector<int> ans(n);
  int gives = 0;
  for(int i = 1; ; i++)
  {
    if(((i * (i + 1)) / 2) > c)
    {
      gives = i - 1;
      break;
    }
  }
  int fullCycles = gives / n;
  int remaining = gives % n;
  if(!fullCycles)
  {
    int x = 0;
    for(; c >= x + 1; x++)
    {
      ans[x] = x + 1;
      c -= ans[x];
    }
    ans[x] = c;
  }
  else
  {
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
      ans[i] = fullCycles * (i + 1 + ((fullCycles - 1) * n) / 2);
      if((n+1) % 2 == 0) //the problematic logic
      {
        ans[i]++;
      }
      sum += ans[i];
    }
    for(int i = 0; i < remaining; i++)
    {
      ans[i] += n * fullCycles + i + 1;
      sum += n * fullCycles + i + 1;
    }
    ans[remaining] += c - sum;
  }
  return ans;
}
int main()
{
  int n = 0, candies = 0;
  cin >> n >> candies;
  vector<int> ans = solve(n, candies);
  for(int i = 0; i < n; i++)
  {
    cout << ans[i] << " ";
  }
}
//x + x + n + x + 2*n...
//= fC*x + (1 + 2 + 3 + ...) * n
//=fC*x + (fc) * (fc-1) * n / 2
//fC * (x + ((fc-1)*n)/2) - (fC-1) * (x + ((fc-2)*n)/2)
//=xfC + fC*(fC-1)*n/2 - xfC + x - (fC-1)*(fC-2)*n/2
//=x + n/2(fC^2 - fC -fC^2 +fC + 2fC - 2)
//=x + n*(fc - 1)
