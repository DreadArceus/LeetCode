/*Did this by the following methods:
  1. Make the Pascal's triangle, return the kth row [O(K*K) space]
  2. Using 2 1D vectors, store the last pascal triangle row and calculate the next.
  3. Using C(n, r) to make the pascal triangle row.
      *Further optimisation, store n! before calculating C(n, r)
      **long long cant store big factorials(>20), gonna try this method later.
*/
#include <iostream>
#include <vector>
using namespace std;
long long fac(int n)
{
  long long ans = 1;
  for(int i = 2; i <= n; i++)
  {
    ans *= i;
  }
  return ans;
}
int C(long long nF, int n, int r)
{
  return nF / (fac(r) * fac(n - r));
}
vector<int> solve(int rowIndex)
{
  vector<int> ans(rowIndex + 1);
  long long nFac = fac(rowIndex);
  for(int i = 0; i < ans.size(); i++)
  {
    ans[i] = C(nFac, rowIndex, i);
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
