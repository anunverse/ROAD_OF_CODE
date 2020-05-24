//https://www.acwing.com/problem/content/93/
/*
    二进制状态压缩(一个长度为m的bool数组可由一个m位的二进制整数来表示)
    1、保存两个信息，第一是: 当前经过的点； f第二是：当前所在点
        使用二维数组f来表示，第一维用 一个m位的二进制整数来表示
    2、f[i][j] = f[i^(1<<j)][k] + w[k][j]; f[1][0] = 0;
*/

#include <iostream>
#include <cstring>
using namespace std;

const int N = 20, M = 1 << 20;

int w[N][N], f[M][N];
int n;

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> w[i][j];
    
    memset(f, 0x3f, sizeof f);
    f[1][0] = 0;
    for(int i = 1; i < 1 << n; i++)
        for(int j = 0; j < n; j++)
            if((i >> j) & 1)
            for(int k = 0; k < n; k++)
            if(i ^ (1 << j) >> k & 1)
                f[i][j] = min(f[i][j], f[i ^ (1 << j)][k] + w[k][j]);
    
    cout << f[(1 << n) - 1][n-1];
    
    return 0;
}
