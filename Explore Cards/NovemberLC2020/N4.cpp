//Tree... Only idea is to make literally all possible trees and check O(n * time to make a tree)
//Leaving this for when i know tree stuff.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solve(int n, vector<vector<int>> edges)
{
    if(n == 1)
    {
        return {0};
    }
    unordered_map<int, int> hashMap;
    for(vector<int> edge : edges)
    {
        hashMap[edge[0]]++;
        hashMap[edge[1]]++;
    }
    vector<int> ans(n, 0);
    int maxF = 0;
    for(pair<int, int> f : hashMap)
    {
        if(maxF < f.second)
        {
            maxF = f.second;
            ans[0] = f.first;
        }
    }
    return ans;
}

int main()
{
    int n = 0;
    cin >> n;
    vector<vector<int>> edges(n, vector<int>(2, 0));
    for(int i = 0; i < n - 1; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }
    vector<int> ans = solve(n, edges);
    for(int x : ans)
    {
        cout << x << " ";
    }
}