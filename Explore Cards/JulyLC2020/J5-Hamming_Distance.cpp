#include <iostream>
#include <vector>
#include <cmath>

int binarize(int &x)
{
  for(int i = 0; i < 32; i++)
  {
      if(x < pow(2,i))
      {
        x -= pow(2 , i - 1);
        return i - 1;
      }
      else if(x == pow(2,i))
      {
        x = 0;
        return i;
      }
  }
  return 0;
}

int main()
{
  int x, y;
  std::cin >> x >> y;
  std::vector<int> xb(31);
  std::vector<int> yb(31);
  while(x > 0)
  {
    xb[binarize(x)] = 1;
  }
  while(y > 0)
  {
    yb[binarize(y)] = 1;
  }
  int cnt = 0;
  for(int i = 0; i < 32; i++)
  {
    if(yb[i] != xb[i])
    {
      cnt++;
    }
  }
  std::cout << cnt;
  return 0;
}
