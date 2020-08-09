//LeetCode forced using vectors, here's my set solution anyways.
#include <iostream>
#include <set>
using namespace std;
int solve(set<int> st, int k)
{
  for(int i = 1;; i++)
  {
    if(st.find(i) == st.end())
    {
      k--;
    }
    if(k == 0)
    {
      return i;
    }
  }
}
int main()
{
  int n = 0, k = 0;
  cin >> n >> k;
  set<int> st;
  for(int i = 0; i < n; i++)
  {
    int loc = 0;
    cin >> loc;
    st.insert(loc);
  }
  int ans = solve(st, k);
  cout << "The result is: " << ans;
}
