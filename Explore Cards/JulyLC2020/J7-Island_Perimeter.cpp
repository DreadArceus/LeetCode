#include <iostream>
#include <vector>

using namespace std;

int calcPerimeter(vector<vector<int> > grid);

int main()
{
  int r, c;
  cin >> r >> c;
  vector<vector<int> > G(r);
  for(int i = 0; i < G.size(); i++)
  {
    for(int j = 0; j < c; j++)
    {
      int x;
      cin >> x;
      G[i].push_back(x);
    }
  }
  int per = calcPerimeter(G);
  cout << "The perimeter of the land is " << per;
}

int calcPerimeter(vector<vector<int> > grid)
{
  int cnt = 0;
  for(int i = 0; i < grid.size(); i++)
  {
    for(int j = 0; j < grid[0].size(); j++)
    {
      if(grid[i][j] == 1)
      { //The following || account for the edges while avoiding errors
        if(i == grid.size() - 1 || grid[i+1][j] == 0)
        {
          cnt++;
        }
        if(j == grid[0].size()-1 || grid[i][j+1] == 0)
        {
          cnt++;
        }
        if(i == 0 || grid[i-1][j] == 0)
        {
          cnt++;
        }
        if(j == 0 || grid[i][j-1] == 0)
        {
          cnt++;
        }
      }
    }
  }
  return cnt;
}
