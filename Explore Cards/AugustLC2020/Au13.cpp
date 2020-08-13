//Version 0.1: Made a Permutation Iterator x.x
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class CombinationIterator
{
public:
  CombinationIterator(string characters, int combinationLength)
  {
    this->s = characters;
    this->len = combinationLength;
  }
  string next()
  {
    next_permutation(s.begin(), s.end());
    return this->s;
  }
  bool hasNext()
  {
    string x = this->s;
    return next_permutation(x.begin(), x.end());
  }
private:
  string s;
  int len;
};
int main()
{
  int l = 0;
  string s = "";
  cin >> l >> s;
  CombinationIterator *it = new CombinationIterator(s, l);
  while(it->hasNext())
  {
    cout << it->next() << "\n";
  }
}
