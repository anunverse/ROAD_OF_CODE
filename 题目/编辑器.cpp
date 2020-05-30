// https://www.acwing.com/problem/content/130/

#include <iostream>
#include <stack>
using namespace std;

const int N = 1000010;

stack<int> a;
stack<int> b;
long long sum[N], f[N];

int main()
{
    int n; 
    cin >> n;
    while (n -- )
    {
        f[0] = -1e8;
        char c;
        cin >> c;
        if (c == 'I')
        {
            int x;
            cin >> x;
            a.push(x);
            sum[a.size()] = sum[a.size() - 1] + x;
            f[a.size()] = max(f[a.size() - 1], sum[a.size()]);
        }
        else if (c == 'L')
        {
            b.push(a.top());
            a.pop();
        }
        else if (c == 'D')
        {
            if (!a.empty())
                a.pop();
        }
        else if (c == 'R')
        {
            if (!b.empty())
            {
                a.push(b.top());
                sum[a.size()] = sum[a.size() - 1] + b.top();
                f[a.size()] = max(f[a.size() - 1], sum[a.size()]);
                b.pop();
            }
        }
        else if (c == 'Q')
        {
            int x;
            cin >> x;
            cout << f[x] << endl;
        }
    }
    return 0;
}
