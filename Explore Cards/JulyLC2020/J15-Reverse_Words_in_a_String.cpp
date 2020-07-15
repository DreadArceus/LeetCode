#include <iostream>
#include <string>
#include <vector>
using namespace std;
string reverseWords(string s)
{
  string W = "";
  vector<string> words;
  for(int i = 0; i < s.length(); i++)
  {
    if(s[i] == ' ')
    {
      if(W != "")
      {
        words.push_back(W);
        W = "";
      }
    }
    else
    {
      W += s[i];
    }
  }
  if(W != "")
  {
    words.push_back(W);
  }
  string rS = "";
  for(int i = 0; i < words.size(); i++)
  {
    rS += words[words.size() - 1 - i];
    if(i != words.size() - 1)
    {
      rS += " ";
    }
  }
  return rS;
}
int main()
{
  string s;
  getline(cin, s);
  string revS = reverseWords(s);
  cout << "The result is: " << revS;
}
