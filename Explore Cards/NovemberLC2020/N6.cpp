//v1: Brute Force or Linear Search i guess, 48/61 cases
//v2: Binary Search
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int solve(vector<int> nums, int threshold)
{
    long long l = 1, r = INT32_MAX;
    while(r != l + 1)
    {
        int m = (l + r - 1) / 2;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += ceil(nums[i]/(double)m);
        }
        if(sum > threshold)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    return l;
}
int main()
{
    int n = 0, th = 0;
    cin >> n >> th;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    int ans = solve(v, th);
    cout << ans;
}