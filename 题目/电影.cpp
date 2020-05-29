// https://www.acwing.com/problem/content/105/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200010;
const int M = 200010;

int n, m;
vector<int> a, b, c;
vector<int> alls;
int ans[N];

int query(int x){
    return lower_bound(alls.begin(), alls.end(), x) - alls.begin();
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++) 
    {
        int x; 
        cin >> x;
        a.push_back(x);
        alls.push_back(x);
    }
    
    cin >> m;
    
    for(int i = 0; i < m; i ++) 
    {
        int x; 
        cin >> x;
        b.push_back(x);
        alls.push_back(x);
    }
    for(int i = 0; i < m; i ++) 
    {
        int x; 
        cin >> x;
        c.push_back(x);
        alls.push_back(x);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    
    for(int i = 0; i < n; i ++) ans[query(a[i])] ++;
    for(int i = 0; i < m; i ++) 
    {
        int ansb = ans[]
    }
    
    return 0;
}
