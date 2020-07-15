#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<vector<int> > subs(vector<int> nums)
{
  vector<vector<int> > a(pow(2, nums.size()));
  for(int i = 1; i < a.size(); i++)
  {
    for(int j = 0; j < ; j++)
    {
      a[i].push_back(j);
    }
  }

}
int main()
{
  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  vector<vector<int> > subsets = subs(v);
}
