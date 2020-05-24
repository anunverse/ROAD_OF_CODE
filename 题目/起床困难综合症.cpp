//https://www.acwing.com/problem/content/description/1000/
#include<iostream>
#include<cstring>
using namespace std;

const int N = 100010;

string op;
int t;
int n,m;

pair<string, int> z[N];

int cal(int x, int now)
{
    for(int i=0;i<n;i++)
    {
        if(z[i].first=="AND") now &= ((z[i].second >> x) & 1);
        else if(z[i].first=="OR") now |= ((z[i].second >> x) & 1);
        else now ^= ((z[i].second >> x) & 1);
    }
    return now;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>z[i].first>>z[i].second;
    int ans = 0, sum = 0;
    for(int i=29;i>=0;i--)
    {
        int res0 = cal(i,0);
        int res1 = cal(i,1);
        if(sum + (1<<i)<=m && res1 == 1 && res0 == 0)
            sum += 1 << i, ans += res1 << i;
        else ans += res0 << i;
    }
    cout<<ans;
    return 0;
}
