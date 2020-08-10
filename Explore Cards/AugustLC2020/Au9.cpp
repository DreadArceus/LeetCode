//The max horizantal + vertical distance is the answer
//But i have no idea how to implement this in a reasonable time complexity
#include <iostream>
#include <vector>
using namespace std;
int minMinutes(vector<vector<int> > v)
{
  int maxSolo = 0;
  for(int i = 0; i < v.size(); i++)
  {
    for(int j = 0; j < v[0].size(); j++)
    {

    }
  }
}
int main()
{
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int> > grid(n);
  for(int i = 0; i < n; i++)
  {
    vector<int> local(m);
    for(int j = 0; j < m; j++)
    {
      cin >> local[j];
    }
    grid[i] = local;
  }
  int ans = minMinutes(grid);
  cout << "The result is: " << ans;
}
