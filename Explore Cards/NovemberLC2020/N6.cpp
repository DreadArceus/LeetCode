//v1: Brute Force or Linear Search i guess, 48/61 cases
//Apparently binary search can make this faster
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int solve(vector<int> nums, int threshold)
{
    for(double x = 1; ; x++)
    {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += ceil(nums[i]/x);
        }
        if(sum <= threshold)
        {
            return x;
        }
    }
    return -1;
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