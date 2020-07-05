#include <iostream>
#include <vector>
#include <cmath>

int main()
{
  int N, x = 0;
  std::cin >> N;
  std::vector<int> a(288);
  for(int k = 0; k <= 5; k++)
  {
    for(int j = 0; j <= 5; j++)
    {
      for(int i = 0; i <= 7; i++)
      {
        a[x] = pow(2,i) * pow(3, j) * pow(5, k);
        x++;
      }
    }
  }
  sort(a.begin(), a.end());
  std::cout << a[N-1];
  return 0;
}
