#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> solve(vector<int> candidates, int target)
{
    for(int i = 0; i < candidates.size(); i++)
    {
        if(candidates[i] > target)
        {
            candidates.erase(candidates.begin() + i--);
        }
    }
    vector<vector<int>> solution;
    
    return solution;
}

int main()
{
    int n = 0, tar = 0;
    cin >> n;
    vector<int> cand(n);
    for(int i = 0; i < n; i++)
    {
        cin >> cand[i];
    }
    cin >> tar;

    vector<vector<int>> ans = solve(cand, tar);

    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}