// https://www.acwing.com/problem/content/112/

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

const int N = 2510;
int c, l;

pair<int, int> cows[N];


int main()
{
    cin >> c >> l;
    for (int i = 0; i < c; i ++ ) cin >> cows[i].first >> cows[i].second;
    map<int, int> spfs;
    for (int i = 0; i < l; i ++ )
    {
        int spf, cover;
        cin >> spf >> cover;
        spfs[spf] += cover;
    }
    sort(cows, cows + c);
    spfs[0] = spfs[1001] = c;
    int res = 0;
    for (int i = c - 1; i >= 0; i -- )
    {
        auto spf = spfs.upper_bound(cows[i].second);
        spf --;
        if (spf->first >= cows[i].first)
        {
            res ++;
            if (-- spf->second == 0) spfs.erase(spf);
        }
    }
    cout << res << endl;
    return 0;
}
