// https://www.acwing.com/problem/content/131/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int n, res;
vector<int> path;
stack<int> a;

void dfs(int x)
{
    if (path.size() == n)
    {
        res ++;
        if (res <= 20)
        {
            for (auto i : path) cout << i;
            cout << endl;
        }
        return ;
    }
    
    if (a.size())
    {
        path.push_back(a.top());
        a.pop();
        dfs(x);
        a.push(path.back());
        path.pop_back();
    }
    if ( x <= n)
    {
        a.push(x);
        dfs(x + 1);
        a.pop();
    }
}

int main()
{
    cin >> n;
    dfs(1);
    return 0;
}
