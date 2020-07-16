#include <iostream>
#include <cmath>
using namespace std;

template <class T>
T oPow(T x, int n)
{
  T ans = 1;
  if(n == 0)
  {
    return ans;
  }
  for(int i = abs(n); i > 0; i--)
  {
    ans *= x;
  }
  return pow(ans, abs(n)/n);
}

int main()
{
  double x = 0;
  int n = 0;
  cin >> x >> n;
  double ans = oPow(x, n);
  cout << "The result is: " << ans;
}
