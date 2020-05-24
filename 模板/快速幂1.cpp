#include<iostream>
using namespace std;

int a,b,p;

//快速幂操作
// 2的6次方 = 2^0 * 4^1 * 16^1
int power(int a,int b,int p)
{
    int res = 1;
    for(;b;b>>=1)
    {
        if(b&1) res = (long long)res * a % p;
        a = (long long)a * a % p;
    }
    return res % p;
}

int main()
{
    cin>>a>>b>>p;
    cout<<power(a,b,p);
    return 0;
}
