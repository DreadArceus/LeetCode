#include <iostream>
#include <vector>
using namespace std;
vector<int> solve(int rowIndex)
{
  pair<vector<int>, vector<int>> pT = {{1}, {1, 1}};
  if(rowIndex == 0)
  {
    return pT.first;
  }
  for(int i = 2; i <= rowIndex; i++)
  {
    pT.first = pT.second;
    pT.second.clear();
    pT.second.resize(pT.first.size() + 1);
    pT.second[0] = 1;
    pT.second[pT.second.size() - 1] = 1;
    for(int j = 1; j < pT.second.size() - 1; j++)
    {
      pT.second[j] = pT.first[j - 1] + pT.first[j];
    }
  }
  return pT.second;
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
