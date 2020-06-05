// https://www.acwing.com/problem/content/137/

#include <iostream>
#include <limits.h>
using namespace std;

typedef long long ll;
const int N = 300010;

ll S[N];
int q[N];
int n, m;

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i ++ )
    {
        int x;
        cin >> x;
        S[i] = S[i - 1] + x;
    }
    
    ll res = INT_MIN;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i ++ )
    {
        while (l <= r && q[l] < i - m) l ++;
        res = max(res, S[i] - S[q[l]]);
        while (l <= r && S[q[r]] >= S[i]) r --;
        q[++ r] = i;
    }
    cout << res << endl;
    return 0;
}
