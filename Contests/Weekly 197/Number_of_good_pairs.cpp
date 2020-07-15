#include <iostream>
#include <vector>
using namespace std;
int numIPairs(vector<int> nums)
{
  int cnt = 0;
  for(int i = 0; i < nums.size(); i++)
  {
    for(int j = i + 1; j < nums.size(); j++)
    {
      if(nums[i] == nums[j])
      {
        cnt++;
      }
    }
  }
  return cnt;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < v.size(); i++)
  {
    cin >> v[i];
  }
  int nPairs = numIPairs(v);
  cout << "The result is: " << nPairs;
}
