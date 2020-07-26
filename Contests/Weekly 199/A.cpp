//Thought up a nice use of a map
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
string shuffle(string s, vector<int> indices)
{
  unordered_map<int, char> key;
  for(int i = 0; i < indices.size(); i++)
  {
    key[indices[i]] = s[i];
  }
  string ans = "";
  for(int i = 0; i < indices.size(); i++)
  {
    ans.push_back(key[i]);
  }
  return ans;
}
int main()
{
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> v(n);
  for(int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  string ans = shuffle(s, v);
  cout << "The result is: " << ans;
}
