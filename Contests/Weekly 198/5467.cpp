//TLE
#include <iostream>
#include <vector>
using namespace std;
int mysteriousFunction(vector<int> arr, int l, int r)
{
  if(r < l)
  {
    return -1000000000;
  }
  int ans = arr[l];
  for(int i = l + 1; i <= r; i++)
  {
    ans = ans & arr[i];
  }
  return ans;
}
int lrFinder(vector<int> arr, int target)
{
  int min = abs(mysteriousFunction(arr, 1, 2) - target);
  for(int l = 0; l < arr.size(); l++)
  {
    for(int r = l; r < arr.size(); r++)
    {
      int m = abs(mysteriousFunction(arr, l, r) - target);
      if(m < min)
      {
        min = m;
      }
    }
  }
  return min;
}
int main()
{
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> a(n);
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int ans = lrFinder(a, x);
  cout << ans;
}
