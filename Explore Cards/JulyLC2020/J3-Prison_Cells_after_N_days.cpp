#include <iostream>
#include <vector>

int main()
{
  std::vector<int> a(8);
  for(int i = 0; i < a.size(); i++)
  {
    std::cin >> a[i];
  }
  int N;
  std::cin >> N;
  int x = N % 14;
  if(x == 0)
  {
    x = 14;
  }
  for(x; x > 0; x--)
  {
    std::vector<int> dup(a.size());
    for(int i = 1; i < a.size() - 1; i++)
    {
      if(a[i-1] == a[i+1])
      {
        dup[i] = 1;
      }
    }
    a = dup;
  }
  for(int i : a)
  {
    std::cout << i << " ";
  }
  return 0;
}
