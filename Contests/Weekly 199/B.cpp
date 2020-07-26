//General case = 2 * zeroes + 1
//Leading Zeroes => ignore
//All Zeroes => answer = 0
//Consecutive zeroes => 1 zero.
//Ending zero => half a zero (ans = 2 * zeroes)
#include <iostream>
#include <string>
using namespace std;
int minFlips(string target)
{
  int i = 0, cnt = 0;
  while(i < target.length() && target[i] == '0')
  {
    i++;
  }
  if(i == target.length())
  {
    return 0;
  }
  bool prev_zero = false;
  for(i; i < target.length(); i++)
  {
    if(target[i] == '0' && prev_zero == false)
    {
      prev_zero = true;
      cnt++;
    }
    if(target[i] != '0')
    {
      prev_zero = false;
    }
  }
  if(target[target.length() - 1] == '0')
  {
    return cnt * 2;
  }
  return cnt * 2 + 1;
}
int main()
{
  string s = "";
  cin >> s;
  int ans = minFlips(s);
  cout << "The result is: " << ans;
}
