//My soluttion is no where near the most optimal, must improve later.
#include <vector>
using namespace std;

class RecentCounter {
public:
    RecentCounter()
    {
        requests.resize(0);
    }
    int ping(int t)
    {
        requests.push_back(t);
        for(int i = requests.size() - 1; i >= 0; i--)
        {
            if(requests[i] < t - 3000)
            {
                return requests.size() - i - 1;
            }
        }
        return requests.size();
    }
private:
    vector<int> requests;
};