// https://www.acwing.com/problem/content/104/

#include <iostream>
using namespace std;

const int N = 100010;
double a[N], b[N], sum[N];

int main()
{
    int n, f;
    cin >> n >> f;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    double l = -1e6, r = 1e6, eps = 1e-5;
    
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        for (int i = 1; i <= n; i++)
        {
            b[i] = a[i] - mid;
            sum[i] =  sum[i - 1] + b[i];
        }
        
        double mi = 1e8, ma = -1e8;
        
        for (int i = f; i <= n; i++)
        {
            mi = min(mi, sum[i - f]);
            ma = max(ma, sum[i] - mi);
        }
        if (ma > 0) l = mid;
        else r = mid;
    }
    cout << int(r * 1000) << endl;
    return 0;
}
