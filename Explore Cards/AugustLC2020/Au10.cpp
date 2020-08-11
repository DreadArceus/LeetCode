#include <iostream>
#include <cmath>
#include <string>
using namespace std;
int to_int(char c)
{
  return c - 64;
}
int solve(string s)
{
  int ans = 0;
  for(int i = s.length() - 1; i >= 0; i--)
  {
    ans += to_int(s[i]) * pow(26, s.length() - 1 - i);
  }
  return ans;
}
int main()
{
  string s = "";
  cin >> s;
  int ans = solve(s);
  cout << "The result is: " << ans;
}
