#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool solve(string s)
{
  for(int i = 0; i < s.length() ; i++)
  {
    if(s[i] < 48 || (s[i] < 65 && s[i] > 57) || (s[i] > 90 && s[i] < 97) || s[i] > 122)
    {
      s.erase(s.begin() + i);
      i--;
    }
  }
  if(s.length() == 0)
  {
    return 1;
  }
  int len = s.length() / 2;
  for(int i = 0; i <= len; i++)
  {
    if(s[i] == s[s.length() - i - 1] || (abs(s[i] - s[s.length() - i - 1]) == 32 && s[i] + s[s.length() - i - 1] > 161))
    {
      continue;
    }
    return 0;
  }
  return 1;
}
template<class Ti, class To>
void func(Ti &in, To &o, ifstream &c)
{
  int t  = 0;
  in >> t;
  in.ignore(3, '\n');
  while(t--)
  {
    string s = "";
    getline(in, s);
    bool var = solve(s);
    if(c.is_open())
    {
      int ans = 0;
      c >> ans;
      c.ignore(3, '\n');
      cout << "Testing.. ";
      if(var != ans)
      {
        cout << "Wrong Answer\n";
      }
      else
      {
        cout << "Passed\n";
      }
    }
    o << (var ? "true" : "false") << "\n";
  }
}
int main()
{
  ifstream checkFile, inFile("/Users/dreadarceus/github/LeetCode/Testers/input.txt");
  ofstream outFile;
  if(inFile.is_open())
  {
    checkFile.open("/Users/dreadarceus/github/LeetCode/Testers/correctOutput.txt");
    outFile.open("/Users/dreadarceus/github/LeetCode/Testers/output.txt");
    func(inFile, outFile, checkFile);
  }
  else
  {
    func(cin, cout, checkFile);
  }
}
