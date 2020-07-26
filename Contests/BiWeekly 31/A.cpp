#include <iostream>
using namespace std;
int oddCount(int low, int high)
{
  if(low == 0)
  {
    low++;
  }
  int cnt  = 0;
  for(int i = low; i <= high; i++)
  {
    if(i % 2 != 0)
    {
      cnt++;
    }
  }
  return cnt;
}
int main()
{
  int l = 0, h = 0;
  cin >> l >> h;
  int ans = oddCount(l, h);
  cout << "The result is: " << ans;
}
