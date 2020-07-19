//This logic cannot handle an item having more than one prerequisity effectively.
//Be back after DSA i guess? -18-July-2020
#include <iostream>
#include <vector>
using namespace std;
vector<int> scheduler(int numCourses, vector<vector<int> > prerequisites)
{
  bool check = true;
  vector<int> ans;
  for(int i  = numCourses - 1; i >= 0; i--)
  {
    for(vector<int> a : prerequisites)
    {
      if(a[0] == i)
      {
        check = false;
        break;
      }
    }
    if(check)
    {
      ans.push_back(i);
    }
    check = true;
  }
  for(int j = 0; j < ans.size(); j++)
  {
    for(int i = 0; i < prerequisites.size(); i++)
    {
      if(ans[j] == prerequisites[i][1])
      {
        prerequisites[i][1] = -1;
        ans.push_back(prerequisites[i][0]);
      }
    }
  }
  if(ans.size() != numCourses)
  {
    vector<int> null;
    return null;
  }
  return ans;
}
int main()
{
  int n = 0, k = 0;
  cin >> n >> k;
  vector<vector<int> > p(k);
  for(int i = 0; i < p.size(); i++)
  {
    vector<int> local(2);
    cin >> local[0] >> local[1];
    p[i] = local;
  }
  vector<int> order = scheduler(n, p);
  for(int i = 0; i < order.size(); i++)
  {
    cout << order[i] << " ";
  }
}
