#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> substrFinder(string s)
{
  
}
int main()
{
  string s;
  cin >> s;
  vector<string> ans = substrFinder(s);
  for(int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
}
