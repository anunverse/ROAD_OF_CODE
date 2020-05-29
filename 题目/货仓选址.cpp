// https://www.acwing.com/problem/content/description/106/

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100010;

int a[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a, a + n);
    int res = 0;
    if(! (n & 1))
    {
        for(int i = 1; i <= n; i ++)
            res = res + abs(a[n >> 1] - a[i]);
    }
    else
    {
        for(int i = 1; i <= n; i ++)
            res = res + abs(a[(n + 1) >> 1] - a[i]);
    }
    cout << res <<endl;
}
