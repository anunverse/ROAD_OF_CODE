/*
    https://www.acwing.com/problem/content/798/
    二维前缀和
    S[i, j] = S[i - 1, j] + S[i, j - 1] - S[i - 1, j - 1] + A[i, j]
*/

#include <iostream>
using namespace std;

const int N = 1010;
const int M = 1010;
const int Q = 200010;

int n, m, q;
int mat[N][M];
int sum[N][M];

int main()
{
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> mat[i][j];
            sum[i][j] = sum[i][j - 1] + sum[i - 1][j] + mat[i][j] - sum[i - 1][j - 1];
        }
    }
    while(q--)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int res = 0;
        res = sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x2][y1 - 1] - sum[x1 - 1][y2];
        cout << res << endl;
    }
    return 0;
}
