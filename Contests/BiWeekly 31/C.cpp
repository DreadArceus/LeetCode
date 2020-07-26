//TLE on big file input (9k+ chars)
//First time using sets, pretty cool thingy.
//The constructor and for loop inserts both seem to have same time complexity
//Looked over some solutions, seems like a few DS can be combined to do this.
//be back with the goods -25-July-2020
#include <iostream>
#include <string>
#include <set>
using namespace std;
bool goodSplit(int i, string s)
{
  set<char> sl(begin(s), begin(s) + i), sr(begin(s) + i, end(s));
  return sl.size() == sr.size();
}
int countGoodSplits(string s)
{
  int cnt = 0;
  for(int i = 0; i < s.length(); i++)
  {
    if(goodSplit(i, s))
    {
      cnt++;
    }
  }
  return cnt;
}
int main()
{
  string s = "";
  cin >> s;
  int ans = countGoodSplits(s);
  cout << "The result is: " << ans;
}
