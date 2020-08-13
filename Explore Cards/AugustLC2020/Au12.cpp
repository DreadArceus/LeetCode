/*Did this by the following methods:
  1. Make the Pascal's triangle, return the kth row [O(K*K) space]
  2. Using 2 1D vectors, store the last pascal triangle row and calculate the next.
  3. Using C(n, r) to make the pascal triangle row.
*/
#include <iostream>
#include <vector>
using namespace std;
int fac(int n)
{
  int ans = 1;
  for(int i = 2; i <= n; i++)
  {
    ans *= i;
  }
  return ans;
}
int C(int n, int r)
{
  return fac(n) / (fac(r) * fac(n - r));
}
vector<int> solve(int rowIndex)
{
  vector<int> ans(rowIndex + 1);
  for(int i = 0; i < ans.size(); i++)
  {
    ans[i] = C(rowIndex, i);
  }
  return ans;
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
