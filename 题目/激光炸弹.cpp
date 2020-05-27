// https://www.acwing.com/problem/content/101/
#include <iostream>
using namespace std;

const int N = 5010;

int n, R;
int a[N][N];


int main()
{
    cin >> n >> R;
    while(n -- )
    {
        int x, y, v;
        cin >> x >> y >> v;
        a[x + 1][y + 1] = v;
    }
    
    for(int i = 1; i <= 5001; i ++)
    {
        for(int j = 1; j <= 5001; j ++)
        {
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
    
    int res = 0;
    
    for(int i = R; i <= 5001; i ++)
    {
        for(int j = R; j <= 5001; j ++)
        {
            res = max(res, a[i][j] - a[i - R][j] - a[i][j - R] + a[i - R][j - R]);
        }
    }
    cout << res ;
    return 0;
}
