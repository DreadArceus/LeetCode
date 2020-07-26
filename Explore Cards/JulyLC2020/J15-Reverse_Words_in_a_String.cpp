#include <iostream>
#include <string>
#include <vector>
using namespace std;
//The vector solution can be made faster and in lesser space complexity
//This version fails test case 4 (Runtime Error)
//be back to see why later -15-July-2020
string reverseWords(string s)
{
  string W = "", rS = "";
  for(char c : s)
  {
    if(c == ' ')
    {
      if(W != "")
      {
        rS.insert(0, W + " ");
        W = "";
      }
    }
    else
    {
      W += c;
    }
  }
  if(W != "")
  {
    rS.insert(0, W + " ");
  }
  rS.pop_back();
  return rS;
}
int main()
{
  string s;
  getline(cin, s);
  string revS = reverseWords(s);
  cout << "The result is: " << revS;
}
