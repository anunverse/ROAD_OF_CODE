// https://www.acwing.com/problem/content/94/
/*
    输入样例：
    3
    输出样例：

    3
    2
    2 3
    1
    1 3
    1 2
    1 2 3
*/
#include<iostream>
#include<vector>
using namespace std;

int n;
vector<int> chosen;

void calc(int x)
{
    if(x == n + 1)
    {
        for(int i = 0; i < chosen.size(); i++)  cout << chosen[i] << ' ';
        cout << endl;
        return ;
    }
    calc(x + 1);
    chosen.push_back(x);
    calc(x + 1);
    chosen.pop_back();
}

int main()
{
    cin >> n;
    calc(1);
    return 0;
}
