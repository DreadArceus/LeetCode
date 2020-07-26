#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool recur(vector<vector<char> > grid, string x, int k, int i, int j)
{
  if(k == x.length())
  {
    return true;
  }
  if(i != 0 && grid[i-1][j] == x[k])
  {
    vector<vector<char> > dupe = grid;
    dupe[i-1][j] = 'x';
    if(recur(dupe, x, k + 1, i - 1, j))
    {
      return true;
    }
  }
  if(j != 0 && grid[i][j-1] == x[k])
  {
    vector<vector<char> > dupe = grid;
    dupe[i][j-1] = 'x';
    if(recur(dupe, x, k + 1, i, j - 1))
    {
      return true;
    }
  }
  if(i != grid.size() - 1 && grid[i+1][j] == x[k])
  {
    vector<vector<char> > dupe = grid;
    dupe[i+1][j] = 'x';
    if(recur(dupe, x, k + 1, i + 1, j))
    {
      return true;
    }
  }
  if(j != grid[0].size() - 1 && grid[i][j+1] == x[k])
  {
    vector<vector<char> > dupe = grid;
    dupe[i][j+1] = 'x';
    if(recur(dupe, x, k + 1, i, j + 1))
    {
      return true;
    }
  }
  return false;
}
bool wordSearch(vector<vector<char> > grid, string x)
{
  for(int i = 0; i < grid.size(); i++)
  {
    for(int j = 0; j < grid[0].size(); j++)
    {
      if(grid[i][j] == x[0])
      {
        vector<vector<char> > dupe = grid;
        dupe[i][j] = 'x';
        if(recur(dupe, x, 1, i, j))
        {
          return true;
        }
      }
    }
  }
  return false;
}
int main()
{
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<char> > grid(n);
  for(int i = 0; i < n; i++)
  {
    vector<char> v(m);
    for(int j = 0; j < m; j++)
    {
      cin >> v[j];
    }
    grid[i] = v;
  }
  string x = "";
  cin >> x;
  if(wordSearch(grid, x))
  {
    cout << "True";
  }
  else
  {
    cout << "False";
  }
}
