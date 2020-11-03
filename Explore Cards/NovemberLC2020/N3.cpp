#include <iostream>
#include <string>
using namespace std;
int solve(string s)
{
    int maxP = 0, currP = 0;
    char currC = s[0];
    for(char c : s)
    {
        if(currC == c)
        {
            currP++;
        }
        else
        {
            if(maxP < currP)
            {
                maxP = currP;
            }
            currP = 1;
            currC = c;
        }
    }
    if(maxP < currP)
    {
        maxP = currP;
    }
    return maxP;
}
int main()
{
    string s = "";
    cin >> s;
    int power = solve(s);
    cout << power;
}