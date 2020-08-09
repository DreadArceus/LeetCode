#include <iostream>
#include <string>
using namespace std;
string solve(string s)
{
  string ans;
  while(ans != s)
  {
    ans = s;
    for(int i = 0; i < s.length() - 1 && s.length() > 1; i++)
    {

      if(abs(s[i] - s[i + 1]) == 32)
      {
        s.erase(s.begin() + i);
        s.erase(s.begin() + i);
        i  = ((i) ? i - 2 : -1);
      }
    }
  }
  return ans;
}
/* The following code caused a stack buffer overflow, dunno why right now
  string ans = "";
  while(ans != s)
  {
    s = ans;
    ans = "";
    for(int i = 0; i < s.length() - 1; i++)
    {
      if(abs(s[i] - s[i + 1]) == 32)
      {
        i++;
        continue;
      }
      ans += s[i];
    }
  }
  return ans;
*/
int main()
{
  string s = "";
  cin >> s;
  string ans = solve(s);
  cout << "The result is: " << ans;
}
