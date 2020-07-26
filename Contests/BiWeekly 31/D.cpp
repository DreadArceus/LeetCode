//Seperating into subarrays is hard? -25-July-2020
#include <iostream>
#include <vector>
using namespace std;
int min(vector<int> v)
{
  int x = v[0];
  for(int i = 0; i < v.size(); i++)
  {
    if(v[i] < x)
    {
      x = v[i];
    }
  }
  return x;
}
int minOperations(vector<int> target)
{
  int cnt = 0;
  vector<int> current = target;
  while(true)
  {
    ...
  }
  return cnt;
}
int main()
{
  int n = 0;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  int ans = minOperations(v);
  cout << "The result is: " << ans;
}
