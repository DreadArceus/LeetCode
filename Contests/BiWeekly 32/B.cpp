//incomplete logic
#include <iostream>
#include <string>
#include <map>
using namespace std;
bool possible(string s, string t, int k)
{
  int cycles = k/26 + 1, maxReq = 0;
  map<int, int> m;
  for(int i = 0; i < s.length(); i++)
  {
    int need = s[i] - t[i];
    if(need < 0)
    {
      need += 26;
    }
    if(m.find(need) == m.end())
    {
      m[need] = 1;
    }
    else
    {
      m[need]++;
    }
  }
  for(auto it : m)
  {
    if(it.second > maxReq)
    {
      maxReq = it.second;
    }
  }
  return cycles >= maxReq;
}
int main()
{
  string s = "", t = "";
  int k = 0;
  cin >> k >> s >> t;
  cout << ((possible(s, t, k)) ? "YES" : "NO");
}
