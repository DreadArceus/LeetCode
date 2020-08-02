//I think i need recursion to do this perfectly. - 31-July-2020
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
bool solve(string s)
{
  bool b = true;
  if(s[0] < 'a' && s[1] < 'a')
  {
    for(char c : s)
    {
      if(c >= 'a')
      {
        b = false;
        break;
      }
    }
  }
  else
  {
    for(char c : s)
    {
      if(c < 'a' && c != s[0])
      {
        b = false;
        break;
      }
    }
  }
  return b;
}
template<class Ti, class To>
void func(Ti &in, To &o, ifstream &c)
{
  int t  = 0;
  in >> t;
  while(t--)
  {
    string s = "";
    in.ignore(3, '\n');
    in >> s;
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
    o << (var ? "True" : "False") << "\n";
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
