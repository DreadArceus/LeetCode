#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> solve(vector<int> v)
{
  vector<int> ans;
  sort(v.begin(), v.end());
  int i = 0;
  while(i < v.size() - 1)
  {
    if(v[i] == v[i+1])
    {
      i += 2;
      continue;
    }
    ans.push_back(v[i]);
    i += 1;
  }
  if(i == v.size() - 1)
  {
    ans.push_back(v[i]);
  }
  return ans;
}
int main()
{
  int n = 0;
  cin >> n;
  vector<int> nums(n);
  for(int i = 0; i < nums.size(); i++)
  {
    cin >> nums[i];
  }
  vector<int> ans = solve(nums);
  for(int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
}
