#include <iostream>
#include <vector>
using namespace std;
int minDistance(vector<vector<int> > positions)
//How to minimise equation in 2 variables?
//Partial differentiation = 0, ok in maths but how do i do this in c++? x.x
{

}
int main()
{
  int n;
  vector<vector<int> > v(n);
  for(int i = 0; i < v.size(); i++)
  {
    v[i].push_back(0);
    v[i].push_back(0);
    cin >> v[i][0] >> v[i][1];
  }
  int minSum = minDistance(v);
  cout << "The result is: " << minSum;
}
