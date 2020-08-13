#include <iostream>
#include <vector>
using namespace std;
vector<int> solve(int rowIndex)
{
  vector<vector<int>> pT = {{1}, {1, 1}};
  for(int i = 2; i <= rowIndex; i++)
  {
    vector<int> row(pT[i-1].size() + 1);
    row[0] = 1;
    row[row.size() - 1] = 1;
    for(int j = 1; j < row.size() - 1; j++)
    {
      row[j] = pT[i - 1][j - 1] + pT[i - 1][j];
    }
    pT.push_back(row);
  }
  return pT[rowIndex];
}
int main()
{
  int k = 0;
  cin >> k;
  vector<int> ans = solve(k);
  for(int i : ans)
  {
    cout << i << " ";
  }
}
