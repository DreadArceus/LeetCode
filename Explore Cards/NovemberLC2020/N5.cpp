//Literally odd/even counting, wow
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int solve(vector<int> position)
{
    int cost1 = 0, cost2 = 0;
    for(int p : position)
    {
        if(p % 2 == 0)
        {
            cost1++;
        }
        else
        {
            cost2++;
        }
    }
    return ((cost1 > cost2) ? cost2 : cost1);
}

int main()
{
    int n = 0;
    cin >> n;
    vector<int> pos(n);
    for(int i = 0; i < n; i++)
    {
        cin >> pos[i];
    }
    int ans = solve(pos);
    cout << ans;
}