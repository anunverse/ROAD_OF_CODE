/*
  归并排序应用,求逆序对数量
*/
#include<iostream>
using namespace std;

const int N = 100010;
int a[N],q[N];
int n;
long count;

long merge_sort(int a[],int l,int r)
{
    if(l>=r) return 0;
    int mid = (l+r)>>1;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);
    int i = l, j = mid + 1, k = 0;
    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j]) q[k++] = a[i++];
        else
        {
            count += mid - i + 1;
            q[k++] = a[j++]; 
        }
    }
    while(i<=mid) q[k++] = a[i++];
    while(j<=r) q[k++] = a[j++];
    
    for(int i=l,j=0;i<=r;i++,j++) a[i] = q[j];
    return count;
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    
    cout<<merge_sort(a,0,n-1);
    
    return 0;
}
