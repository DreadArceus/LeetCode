#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
int base10(string s)
{
  int result = 0;
  for(int i = 0; i < s.length(); i++)
  {
    result += (s[i] - '0') * pow(2, s.length() - 1 - i);
  }
  return result;
}
vector<int> leadingZeroRemover(vector<int> x)
{
  for(int i = 0; i < x.size(); i++)
  {
    if(x[i] == 1)
    {
      break;
    }
    if(x[i] == 0)
    {
      x.erase(x.begin() + i);
      i--;
    }
  }
  return x;
}
vector<int> binarise(int x)
{
  if(x == 0)
  {
    vector<int> ans(1);
    return ans;
  }
  vector<int> binary(32);
  if(x == 1)
  {
    binary[31] = 1;
    return leadingZeroRemover(binary);
  }
  for(int i = 1; x > 1; i++)
  {
    if(pow(2, i) > x)
    {
      binary[binary.size() - i] = 1;
      x -= pow(2, i - 1);
      i = 0;
    }
  }
  if(x == 1)
  {
    binary[31] = 1;
  }
  return leadingZeroRemover(binary);
}
string vectorToString(vector<int> v)
{
  string result = "";
  for(int i = 0; i < v.size(); i++)
  {
    result.resize(result.length() + 1);
    result[result.length() - 1] = char(v[i]) + '0';
  }
  return result;
}
string addBinary(string a, string b)
{
  int x = base10(a), y = base10(b);
  vector<int> binary = binarise(x + y);
  return vectorToString(binary);
}
int main()
{
  string a = "", b = "";
  cin >> a >> b;
  string ans = addBinary(a, b);
  cout << "The result is: " << ans;
}
