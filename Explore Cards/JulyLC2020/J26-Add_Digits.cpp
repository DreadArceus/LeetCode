#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> digitiser(int a)
{
  string x = to_string(a);
  vector<int> digits;
  for(char c : x)
  {
    digits.push_back(c - '0');
  }
  return digits;
}
int addDigits(int num)
{
  int ans = num;
  while(ans > 9)
  {
    vector<int> digits = digitiser(ans);
    ans = 0;
    for(int i : digits)
    {
      ans += i;
    }
  }
  return ans;
}
int main()
{
  int num = 0;
  cin >> num;
  int ans = addDigits(num);
  cout << "The result is: " << ans;
}
