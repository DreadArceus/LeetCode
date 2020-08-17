#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool custom(vector<int> a, vector<int> b)
{
  return ((a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0]);
}
int solve(vector<vector<int>> v)
{
  int ans = 0;
  sort(v.begin(), v.end(), custom);
  for(int i = 0; i < v.size(); i++)
  {
    if(v[i][0] == -1000000000)
    {
      continue;
    }
    for(int j = i + 1; j < v.size(); j++)
    {
      if(v[j][0] == -1000000000)
      {
        continue;
      }
      if(v[i][1] > v[j][0])
      {
        ans++;
        v[j][0] = -1000000000;
      }
    }
  }
  return ans;
}
int main()
{
  int n = 0;
  cin >> n;
  vector<vector<int>> v(n);
  for(int i = 0; i < n; i++)
  {
    int a = 0, b = 0;
    cin >> a >> b;
    v[i] = {a, b};
  }
  int ans = solve(v);
  cout << "The result is: " << ans;
}
