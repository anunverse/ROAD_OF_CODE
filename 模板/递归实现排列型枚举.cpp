// https://www.acwing.com/problem/content/95/
/*
    输入样例：
    3
    输出样例：
    1 2 3
    1 3 2
    2 1 3
    2 3 1
    3 1 2
    3 2 1 
*/

#include <iostream>
using namespace std;

const int N = 20;

int order[N]; //按顺序依次记录被选择的整数
bool chosen[N]; //标记被选择的整数
int n;

void calc(int x)
{
    if(x == n + 1)  //问题边界
    {
        for(int i = 1; i <= n; i++) cout << order[i] << ' ';
        cout << endl;
        return ;
    }
    for(int i = 1; i <= n; i++)
    {
        if(chosen[i]) continue;
        order[x] = i;
        chosen[i] = 1;
        calc(x + 1);
        chosen[i] = 0;
    }
}

int main()
{
    cin >> n;
    calc(1);
    return 0;
}
