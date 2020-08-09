//runtime error:
/* terminate called after throwing an instance of 'std::logic_error'
  what():  basic_string::_M_construct null not valid */
//investigating this later, this solution is just brute force recursion anyways.
#include <iostream>
#include <string>
using namespace std;
string reverse(string s)
{
  for(int i = 0; i <= s.length() / 2; i++)
  {
    swap(s[i], s[s.length() - 1 - i]);
  }
  return s;
}
string invert(string s)
{
  for(int i = 0; i < s.length(); i++)
  {
    s[i] = ((s[i]) ? 0 : 1);
  }
  return s;
}
string stringMaker(int n)
{
  if(n == 1)
  {
    return 0;
  }
  return stringMaker(n - 1) + "1" + reverse(invert(stringMaker(n-1)));
}
int main()
{
  int n = 0, k = 0;
  cin >> n >> k;
  string sN = stringMaker(n);
  cout << sN[k - 1];
}
