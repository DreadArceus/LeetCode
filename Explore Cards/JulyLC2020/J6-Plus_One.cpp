#include <iostream>
#include <vector>

int main()
{
  int N;
  std::cin >> N;
  std::vector<int> num(N);
  for(int i = 0; i < num.size(); i++)
  {
    std::cin >> num[i];
  }
  for(int i = num.size() - 1; i >= 0; i--)
  {
    if(num[i] != 9)
    {
      num[i]++;
      break;
    }
    if(i == 0)
    {
      num[i] = 1;
      num.push_back(0);
      break;
    }
    num[i] = 0;
  }
  for(int i = 0; i < num.size(); i++)
  {
    std::cout << num[i] << " ";
  }
  return 0;
}
