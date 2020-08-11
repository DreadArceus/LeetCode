#include <iostream>
#include <vector>
using namespace std;
int solve(vector<int> v)
{
  for(int i = v.size() - 1; i > 0; i--)
  {
    int countMore = 0, countEqual = 0;
    for(auto it : v)
    {
      if(it > i)
      {
        countMore++;
      }
      else if(it == i)
      {
        countEqual++;
      }
    }
    while(countEqual > 0 && countMore < i)
    {
      countEqual--;
      countMore++;
    }
    if(countMore == i)
    {
      return i;
    }
  }
  return -1;
}
int main()
{
  int n = 0;
  cin >> n;
  vector<int> papers;
  while(n--)
  {
    int loc = 0;
    cin >> loc;
    papers.push_back(loc);
  }
  int h = solve(papers);
  cout << "The H-Index is: " << h;
}
