//Version 0.1: Made a Permutation Iterator x.x
//Version 1.0: Problem solved, pretty satisfied with solution
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
/*
[null,true,"fik",true,"fil",true,"fin","fiu","fiy",true,true,"fkl",true,true,"fkn",true,"fku",true,true,true,"fky","fln",true,"flu",true,"fly","fnu",true,true,"fny","fuy",true,true,"iky",true,"iln","ilu","ily","inu",true,true,"iny","iuy",true,true,"kly","knu",true,"kny",true,true,true,"kuy","lny",true,true,true,true,"luy",true,"nuy",false,"nuy","nuy","nuy","nuy","nuy","nuy",false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false]
[null,true,"fik",true,"fil",true,"fin","fiu","fiy",true,true,"fkl",true,true,"fkn",true,"fku",true,true,true,"fky","fln",true,"flu",true,"fly","fnu",true,true,"fny","fuy",true,true,"ikl",true,"ikn","iku","iky","iln",true,true,"ilu","ily",true,true,"inu","iny",true,"iuy",true,true,true,"kln","klu",true,true,true,true,"kly",true,"knu",true,"kny","kuy","lnu","lny","luy","nuy",false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false]
*/
