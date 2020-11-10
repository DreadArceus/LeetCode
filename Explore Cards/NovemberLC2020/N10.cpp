//v1: normal stuff, just a linear search
//also used the combination of horizontal flip and invert
//basically, invert all the things that are equal in value and at opposite positions
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> flipInvert(vector<vector<int>> img)
{
    int n = img.size(), m = img[0].size();
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < (m + 1)/2; j++)
        {
            if(img[i][j] == img[i][m - 1 - j])
            {
                img[i][j] = ((img[i][j]) ? 0 : 1);
                if(m % 2 == 0 || j != m/2)
                {
                    img[i][m - 1 - j] = ((img[i][m - 1 - j]) ? 0 : 1);
                }
            }
        }
    }
    return img;
}

int main()
{
    int n = 0, m =0;
    cin >> n >> m;
    vector<vector<int>> img(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> img[i][j];
        }
    }

    img = flipInvert(img);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << img[i][j] << " ";
        }
        cout << "\n";
    }
}