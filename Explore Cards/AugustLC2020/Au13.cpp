//Version 0.1: Made a Permutation Iterator x.x
//Version 1.0: Problem solved, pretty satisfied with solution
//Most Efficient solution uses Bit Manipulation, be back for that.
#include <iostream>
#include <vector>
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
    updateCombination();
    string x = "";
    for(int i = 0; i < len; i++)
    {
      x.push_back(s[currentCombination[i]]);
    }
    return x;
  }
  bool hasNext()
  {
    for(int i = 0; i < len; i++)
    {
      if(currentCombination.size() == 0 ||
        s.length() - len + i != currentCombination[i])
      {
        return 1;
      }
    }
    return 0;
  }
private:
  string s;
  int len;
  vector<int> currentCombination;
  void updateCombination()
  {
    if(currentCombination.size() == 0)
    {
      currentCombination.resize(len);
      for(int i = 0; i < len; i++)
      {
        currentCombination[i] = i;
      }
    }
    else
    {
      int last = currentCombination.size() - 1;
      for(int i = 0; i > -last - 1; i--)
      {
        if(currentCombination[last + i] != s.size() - 1 + i)
        {
          currentCombination[last + i]++;
          while(i != 0)
          {
            currentCombination[last + i + 1] = currentCombination[last + i] + 1;
            i++;
          }
          break;
        }
      }
    }
  }
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
