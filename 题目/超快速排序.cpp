// https://www.acwing.com/problem/content/description/109/
#include <iostream>
using namespace std;

#define ll long long 

const int N = 500010;
ll a[N], tmp[N];
ll res = 0;

ll merge_sort(ll a[], int l, int r)
{
    if(l>=r) return res;
    int mid = (l + r)>>1;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);
    int i = l, j = mid + 1, k = 0;
    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j]) tmp[k++] = a[i++];
        else tmp[k++] = a[j++], res += mid - i + 1;
    }
    while(i<=mid) tmp[k++] = a[i++];
    while(j<=r) tmp[k++] = a[j++];
    for(int i=l,j=0;i<=r;i++,j++) a[i] = tmp[j];
    return res;
}

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        cout << merge_sort(a, 1, n) << endl;
        res = 0;
    }
    return 0;
}
