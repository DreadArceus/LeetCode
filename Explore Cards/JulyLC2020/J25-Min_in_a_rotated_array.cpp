#include <iostream>
#include <vector>
using namespace std;
int findMin(vector<int> v)
{
  int m = v[0];
  for(int i : v)
  {
    if(i < m)
    {
      m = i;
    }
  }
  return m;
}
int main()
{
  int n = 0;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < v.size(); i++)
  {
    cin >> v[i];
  }
  int ans = findMin(v);
  cout << "The result is: " << ans;
}
