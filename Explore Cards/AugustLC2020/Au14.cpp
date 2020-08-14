#include <iostream>
#include <string>
#include <map>
using namespace std;
int solve(string s)
{
  int len = 0;
  map<char, int> m;
  for(char c : s)
  {
    m[c]++;
  }
  bool foundOdd = 0;
  for(pair<char, int> p : m)
  {
    if(p.second >= 2)
    {
      len += p.second - p.second % 2;
      p.second %= 2;
    }
    if(!foundOdd && p.second != 0)
    {
      foundOdd = 1;
    }
  }
  return len + foundOdd;
}
int main()
{
  string s = "";
  cin >> s;
  int ans = solve(s);
  cout << "The result is: " << ans;
}
