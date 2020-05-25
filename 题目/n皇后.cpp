#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;

const int N = 20;

//n为棋盘大小
int n; 
int order[N];

bool safe(int x, int val)
{
    bool flag = 1;
    for(int i = 1; i < x; i++)
    {
        if(abs(val - order[i]) != (x - i) && val != order[i]) continue;
        else return 0;
    }
    return flag;
}

int num = 0;

void calc(int x)
{
    if(x == n + 1)
    {
        if(num < 3)
        {
            for(int i = 1; i <= n; i++)
                cout << order[i] <<' ';
            cout << endl;
        }
        num ++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(!safe(x, i)) continue;
        order[x] = i;
        calc(x + 1);
    }
   // order[x] = 0;
}

int main()
{
	cin >> n;
	calc(1);
	cout << num;
	return 0;
}
