#include <iostream>
using namespace std;
int numBottles(int numBottles, int numExchange)
{
  int ans = numBottles;
  int empty = numBottles;
  while(empty >= numExchange)
  {
    numBottles = empty / numExchange;
    empty %= numExchange;
    ans += numBottles;
    empty += numBottles;
  }
  return ans;
}
int main()
{
  int x = 0, y = 0;
  cin >> x >> y;
  int ans = numBottles(x, y);
  cout << "The result is: " << ans;
}
