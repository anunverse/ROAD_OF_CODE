//https://www.acwing.com/problem/content/99/

/*  
    假设现在有两个自然数A和B，S是AB的所有约数之和。请你求出S mod 9901的值是多少。
    
    把 A 分解质因数：p1 ^ c1 + p2 ^ c2 + ... + pn ^ cn
    那么A^B: p1 ^ Bc1 + p2 ^ Bc2 + ... + pn ^ Bcn
    所有的约数之和为：(1 + p1 + p1 ^ 2 + ... + p1 ^ Bc1) * (1 + p2 + p2 ^ 2 + ... + p2 ^ Bc2) *... * (1 + p3 + p3 ^ 2 + ... + p3 ^ Bc3)
    （每个质因数中选一个）
    问题转化为：求 sum(p,c) = 1 + 1 + p + p ^ 2 + ... + p ^ c
    若 c 为奇数， sum(p, c) = (1 + p ^ ((c + 1) / 2)) * sum(p, (c - 1)/2)
    若 c 为偶数， sum(p, c) = (1 + p ^ (c / 2)) * sum(p, c / 2 - 1) + p ^ c
    使用快速幂求解
*/

#include <iostream>
using namespace std;

//快速幂模板
int power(int p, int c)
{
    int res = 1;
    for(; c; c >>= 1)
    {
        if(c & 1) res = (long long) res * p % 9901;
        p = (long long)p * p % 9901;
    }
    return res;
}

//本题求和函数
int sum(int p, int c)
{
    if(c == 1) return (1 + p) % 9901;
    if(c == 0) return 1;
    if(!(c & 1)) 
        return (long long)((1 + power(p, c/2)) * sum (p, (c/2 -1)) + power(p,c) ) % 9901;
    else
        return (long long)(1 + power(p, (c + 1)/2) ) * sum(p, (c-1)/2) % 9901;
}

const int MAX_N = 200010;

int m = 0;
 
int prime[MAX_N],c[MAX_N];
 
 //质因数分解模板
void divide(int n)
{
    for(int i = 2; i * i <= n;i++)
    {
        if( n % i == 0) //i为质数
        {
            prime[++m] = i, c[m] = 0;
            while( n % i == 0) n /= i, c[m]++;  //除掉所有的i并计数
        }
    }
    //n为质数
    if(n>1) prime[++m] = n, c[m] = 1;
}

int main()
{
    int A, B;
    cin >> A >> B;
    divide(A);
    int res = 1;
    for(int i = 1; i <= m; i++) res = res * sum(prime[i], B * c[i]) % 9901;
    if(A == 0) cout << 0;
    else cout << res;
    return 0;
}
