//I think i need recursion to do this perfectly. - 31-July-2020
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
vector<string> solve(string s, vector<string> wordDict)
{
  vector<string> x;
  string sentence = " ", word = "";
  for(int i = 0; i < s.length(); i++)
  {
    word += s[i];
    if(i )
    for(int j = 0; j < wordDict.size(); j++)
    {
      if(word == wordDict[j])
      {
        sentence.insert(sentence.length() - 1, word + " ");
        word = "";
        break;
      }
    }
  }
  x.push_back(sentence);
  return x;
}
template<class Ti, class To>
void func(Ti &in, To &o, ifstream &c)
{
  int t  = 0;
  in >> t;
  while(t--)
  {
    int n = 0;
    string s = "";
    in.ignore(3, '\n');
    in >> s >> n;
    vector<string> d(n);
    for(int i = 0; i < n; i++)
    {
      in >> d[i];
    }
    vector<string> var = solve(s, d);
    //if(c.is_open())
    // {
    //   int ans = 0;
    //   c >> ans;
    //   c.ignore(3, '\n');
    //   cout << "Testing.. ";
    //   if(var != ans)
    //   {
    //     cout << "Wrong Answer\n";
    //     o << "x ";
    //   }
    //   else
    //   {
    //     cout << "Passed\n";
    //   }
    // }
    for(int i = 0; i < var.size(); i++)
    {
      o << var[i] << "\n";
    }
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
