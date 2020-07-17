#include <iostream>
#include <vector>
using namespace std;
vector<int> frequencyAnalyser(vector<int> nums, int k)
{
  vector<vector<int> > f;
  sort(nums.begin(), nums.begin() + nums.size());
  int current = nums[0], cnt = 1;
  for(int i = 1; i <= nums.size(); i++)
  {
    if(i == nums.size() || nums[i] != current)
    {
      vector<int> local(2);
      local[0] = current;
      local[1] = cnt;
      f.push_back(local);
      if(i == nums.size())
      {
        break;
      }
      current = nums[i];
      cnt = 1;
    }
    else
    {
      cnt++;
    }
  }
  vector<int> ans(k);
  for(int j = k; j > 0; j--)
  {
    int max = 0, indMax = 0;
    for(int i = 0; i < f.size(); i++)
    {
      if(f[i][1] > max)
      {
        max = f[i][1];
        indMax = i;
      }
    }
    ans[j - 1] = f[indMax][0];
    f[indMax][1] = 0;
  }
  return ans;
}
int main()
{
  int n = 0, k = 0;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  cin >> k;
  vector<int> ans = frequencyAnalyser(a, k);
  for(int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
}
