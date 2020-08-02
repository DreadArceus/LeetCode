//Not sorting all the time causes WA because the answer isnt min
//Sorting all the time causes TLE
//Came up with a less time consuming case specific sort, accepted.
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
bool key(vector<int> a, vector<int> b)
{
  return a[1] > b[1];
}
int solve(vector<char> tasks, int n)
{
  unordered_set<char> s(tasks.begin(), tasks.end());
  vector<vector<int> > f;
  for(char cx : s)
  {
    vector<int> local(4);
    local[0] = cx;
    local[1] = 0;
    local[2] = true;
    local[3] = 0;
    for(char cy : tasks)
    {
      if(cx == cy)
      {
        local[1]++;
      }
    }
    f.push_back(local);
  }
  int i = 0, x = 0;
  bool go = true;
  sort(f.begin(), f.end(), key);
  while(i != tasks.size())
  {
    x++;
    for(int j = 0; j < f.size(); j++)
    {
      if(!f[j][2])
      {
        if(f[j][3] == n)
        {
          f[j][2] = true;
        }
        f[j][3]++;
      }
      if(go && f[j][2] && f[j][1] > 0)
      {
        f[j][1]--;
        i++;
        f[j][2] = false;
        f[j][3] = 0;
        go = false;
        for(int z = j + 1; z < f.size(); z++)
        {
          if(f[j][1] < f[z][1])
          {
            swap(f[j], f[z]);
            break;
          }
        }
      }
    }
    go = true;
    // sort(f.begin(), f.end(), key);
  }
  return x;
}
template<class Ti, class To>
void func(Ti &in, To &o, ifstream &c)
{
  int t  = 0;
  in >> t;
  in.ignore(3, '\n');
  while(t--)
  {
    int n = 0, k = 0;
    in >> n >> k;
    in.ignore(3, '\n');
    vector<char> v(n);
    for(int i = 0; i < n; i++)
    {
      in >> v[i];
    }
    int var = solve(v, k);
    if(c.is_open())
    {
      int ans = 0;
      c >> ans;
      c.ignore(3, '\n');
      cout << "Testing.. ";
      if(var != ans)
      {
        cout << "Wrong Answer\n";
        o << "x ";
      }
      else
      {
        cout << "Passed\n";
      }
    }
    o << var << "\n";
  }
}
int main()
{
  ifstream checkFile, inFile("/Users/dreadarceus/github/LeetCode/Testers/input.txt");
  ofstream outFile;
  if(inFile.is_open())
  {
    checkFile.open("/Users/dreadarceus/github/LeetCode/Testers/correctOutput.txt");
    outFile.open("/Users/dreadarceus/github/LeetCode/Testers/output.txt");
    func(inFile, outFile, checkFile);
  }
  else
  {
    func(cin, cout, checkFile);
  }
}
