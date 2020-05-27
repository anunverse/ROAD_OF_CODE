// https://www.acwing.com/problem/content/102/
#include <iostream>
using namespace std;

#define LL long long
const int N = 100010;

LL a[N];
LL b;
int n;

int main()
{
    cin >> n;
    LL pos = 0, nea = 0;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        b = a[i] - a[i - 1];
        if(i > 1 && b > 0) pos += b;
        else if(i > 1 && b < 0) nea -= b;
    }
    cout << max(pos, nea) << endl;
    cout << abs(pos - nea) + 1;
    return 0;
}
