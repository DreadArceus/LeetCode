//Everything is good except cases like "aabbaa" (a2b2a2)
//where deleting the 'b's doesnt just make the cString a2a2, it is now a4.
//Changing a2a2 into a4 isn't the hard part,
//the hard part is choosing to delete the 'bb'.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> frequencyDistribution(string s)
{
  vector<int> ans;
  char current = s[0];
  int cnt = 0;
  for(int i = 0; i < s.length(); i++)
  {
    if(current == s[i])
    {
      cnt++;
    }
    else
    {
      ans.push_back(cnt);
      current = s[i];
      cnt = 1;
    }
  }
  ans.push_back(cnt);
  return ans;
}
int minI(vector<int> v)
{
  int ans = 0;
  for(int i = 0; i < v.size(); i++)
  {
    if(v[i] < v[ans] && v[i] != 0)
    {
      ans = i;
    }
  }
  return ans;
}
int compLength(vector<int> v)
{
  int l = 0;
  for(int i = 0; i < v.size(); i++)
  {
    if(v[i] < 2)
    {
      l += v[i];
    }
    else if(v[i] < 10)
    {
      l += 2;
    }
    else if(v[i] == 100)
    {
      l += 4;
    }
    else
    {
      l += 3;
    }
  }
  return l;
}
int lengthOfCompressedStr(string s, int k)
{
  vector<int> f = frequencyDistribution(s);
  while(k--)
  {
    f[minI(f)]--;
  }
  return compLength(f);
}
int main()
{
  int k = 0;
  string s = "";
  cin >> k >> s;
  int len = lengthOfCompressedStr(s, k);
  cout << "The result is: " << len;
}
