//Doing this with loops is easy, no idea how to do it w/o loops -4-August-2020
#include <iostream>
#include <fstream>
using namespace std;
bool solve(int x)
{
  while(x >= 4 && x % 4 == 0)
  {
    x /= 4;
  }
  return x == 1;
}
template<class Ti, class To>
void func(Ti &in, To &o, ifstream &c)
{
  int t  = 0;
  in >> t;
  while(t--)
  {
    int x = 0;
    in.ignore(3, '\n');
    in >> x;
    bool var = solve(x);
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
