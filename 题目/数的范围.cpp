/*
    求单调（增）数组中第一次和最后一次出现某数的位置
    二分求解：
    1、mid = (l + r + 1) >> 1
       if(check(mid)) = true :  l = mid
       else:  r = mid - 1
    2、mid = (l + r) >> 1
       if(check(mid)) = true :  r = mid
       else:  l = mid + 1
    二分问题，理解了原理是个很简单的问题。值得注意的地方是：第一部分 mid = (l + r + 1) >> 1; 不加1会导致死循环。
*/
#include<iostream>
using namespace std;

const int N = 100010;
int n,m;
int a[N];

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    while(m--)
    {
        int x;
        cin>>x;
        int l = 0, r = n - 1;
        while(l<r)
        {
            int mid = (l+r)>>1;
            if(a[mid]>=x) r = mid;
            else l = mid + 1;
        }
        if(a[l]!=x) cout<<"-1 -1"<<endl;
        else
        {
            cout<<l<<' ';
            r = n - 1;
            while(l<r)
            {
                int mid = (l+r+1)>>1;
                if(a[mid]<=x) l = mid;
                else r = mid - 1;
            }
            cout<<r<<endl;
        }
    }
    return 0;
}
