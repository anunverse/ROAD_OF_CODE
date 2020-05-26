/*
    https://www.acwing.com/problem/content/797/
    一维前缀和
*/
#include<iostream>
using namespace std;

const int N = 100010;
int n, m;
int a[N], sum[N];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    while(m--)
    {
        int l, r;
        cin >> l >> r;
        cout << sum[r ] - sum[l - 1] << endl;
    }
    return 0;
}
