/* 快排模板
   快速排序是在“分治”的基础上的：
   1、确定分界点x，中点比较好；
   2、根据x的值把区间分成两半，使得第一个区间所有的值<=x，第二个区间的值>=x；
   3、递归处理左右区间
*/
#include<iostxream>
using namespace std;

const int N = 100010;
int n;
int a[N];

void quick_sort(int a[], int l, int r)
{
    if(l >= r) return ;
    int i = l - 1, j = r + 1, x = a[l+r>>1];
    //这里使用i和j分别为-1，+1，值得注意
    while(i < j)
    {
        do i++; while(a[i]<x);
        do j--; while(a[j]>x);
        if(i<j) swap(a[i],a[j]);
    }
    quick_sort(a, l, j);
    quick_sort(a,j+1,r);
}

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++ ) cin >> a[i];
    
    quick_sort(a, 0, n-1); 
    
    for(int i = 0; i < n; i++) cout << a[i] << ' ';
    return 0;
}
