#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > zeroTriplets(vector<int> a);

int main()
{
  int N;
  cin >> N;
  vector<int> a(N);
  for(int i = 0; i < a.size(); i++)
  {
    cin >> a[i];
  }
  vector<vector<int> > zt = zeroTriplets(a);

  for(int i = 0; i < zt.size(); i++)
  {
    for(int j = 0; j < 3; j++)
    {
      cout << zt[i][j] << " ";
    }
    cout << "\n";
  }
}

vector<vector<int> > zeroTriplets(vector<int> a) //Maybe i need DS before this?
{
  vector<vector<int> > z;
  for(int i = 0; i < a.size(); i++)
  {
    for(int j = i + 1; j < a.size(); j++)
    {
      for(int k = j + 1; k < a.size(); k++)
      {
        if(a[i] + a[j] + a[k] == 0)
        {
          vector<int> zz(3);
          zz[0] = a[i];
          zz[1] = a[j];
          zz[2] = a[k];
          z.push_back(zz);
        }
      }
    }
  }
  return z;
}
