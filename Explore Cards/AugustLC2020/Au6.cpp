#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> findDuplicates(vector<int> v)
{
  if(!v.size())
  {
    return {};
  }
  vector<int> ans;
  sort(v.begin(), v.end());
  for(int i = 0; i < v.size() - 1; i++)
  {
    if(v[i] == v[i + 1])
    {
      ans.push_back(v[i]);
      i++;
    }
  }
  return ans;
}
int main()
{
  int t = 0;
  cin >> t;
  while(t--)
  {
    int n = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
      cin >> v[i];
    }
    vector<int> ans = findDuplicates(v);
    for(int i = 0; i < ans.size(); i++)
    {
      cout << ans[i] << " ";
    }
    cout << "\n";
  }
}
