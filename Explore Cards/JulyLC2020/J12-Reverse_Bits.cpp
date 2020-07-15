#include <iostream>
#include <vector>
#include <cstdint>
#include <cmath>
using namespace std;
vector<int> binarise(uint32_t n)
{
  vector<int> v(32);
  for(int j = 31; ; j--)
  {
    if((long long)pow(2, j) <= n)
    {
      v[v.size() - j - 1] = 1;
      n -= pow(2, j);
    }
    if(n == 1)
    {
      v[v.size() - 1] = 1;
      break;
    }
    else if(n == 0)
    {
      break;
    }
  }
  return v;
}
uint32_t revBits(uint32_t n)
{
  vector<int> b = binarise(n);
  uint32_t a = 0;
  for(int i = 0; i < b.size(); i++)
  {
      a += b[i] * pow(2, i);
  }
  return a;
}
int main()
{
  uint32_t n;
  cin >> n;
  uint32_t ans = revBits(n);
  cout << "The result is: " << ans;
}
