#include <iostream>

int main()
{
  int N;
  std::cin >> N;
  for(long i = 1; ; i++)
  {
    if(N - ((i*(i+1))/2) < 0)
    {
      std::cout << i - 1;
      return 0;
    }
  }
}
