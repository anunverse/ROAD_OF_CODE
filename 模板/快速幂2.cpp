// https://www.acwing.com/problem/content/92
#include<iostream>
using namespace std;

#define LL long long
LL a,b,p;

//类似于快速幂，a*6 = a*1*0 + a*2*1 + a*4*1 = 1a * 0 + 2a * 1 + 4a * 1
LL mul(LL a, LL b, LL p)
{
    LL res = 0;
    for(;b;b>>=1)
    {
        if(b&1) res = (res +  a) % p;
        a = a * 2 % p;
    }
    return res;
}

//直接丢弃乘法的高位溢出
LL mul2(LL a, LL b, LL p)
{
    a %= p, b %= p;
    LL c = (long double) a * b / p;
    LL ans = a * b - c * p;

    return ans;
}


int main()
{
    cin>>a>>b>>p;
    cout<<mul2(a,b,p);
    return 0;
}
