// https://www.acwing.com/problem/content/103/

#include <iostream>
#include <map>
using namespace std;

const int N = 10010;
int n, p, h, m;
int H[N], w[N];
map<pair<int, int>,bool> d;

int main()
{
    cin >> n >> p >> h >> m;
    while(m --)
    {
        int q, v;
        cin >> q >> v;
        if(q > v) swap(q, v);
        if(d[make_pair(q, v)]) continue;
        else
        {
            H[q + 1] -- ;
            H[v] ++ ;
            d[make_pair(q, v)] = true;
        }
    }
    
    for(int i = 1; i <= n; i ++)
    {
        w[i] = w[i - 1] + H[i];
        cout << w[i] + h << endl;
    }
    
    return 0;
}
