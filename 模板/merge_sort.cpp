/*  
    归并排序，稳定算法，O(NlogN),二路归并
    1、确定分界点： mid = l+r>>1; 下标
    2、递归排序
    3、合并数组 (开辟额外空间,排序后需复制进原数组)
*/
#include<iostream>
using namespace std;

const int N = 100010;
int a[N],tep[N];
//tep为额外空间，存储合并后的数组，最后要复制进a数组
int n;

void merge_sort(int a[],int l,int r)
{
   if(l>=r) return ;
   int mid = l+r>>1;
   merge_sort(a,l,mid);
   merge_sort(a,mid+1,r);
   int k = 0, i = l, j = mid + 1;
   while(i<=mid && j<=r)
   {
       if(a[i]<=a[j]) tep[k++] = a[i++];
       else tep[k++] = a[j++];
   }
   while(i<=mid) tep[k++] = a[i++];
   while(j<=r) tep[k++] = a[j++];
   
   for(int i=l,j=0;i<=r;i++,j++) a[i] = tep[j];
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    merge_sort(a,0,n-1);
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
}
