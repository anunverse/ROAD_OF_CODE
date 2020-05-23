#include<iostream>
using namespace std;

const int N = 100010;
int head,idx;
int e[N],ne[N];

void init()
{
    head = -1;
    idx = 0;
}

void insert_h(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx++;
}

void insert_I(int k,int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

void del(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    int M;
    cin>>M;
    init();
    while(M--)
    {
        char op;
        cin>>op;
        if(op=='H')
        {
            int x;
            cin>>x;
            insert_h(x);
        }
        if(op=='I')
        {
            int x,k;
            cin>>k>>x;
            insert_I(k-1,x);
        }
        if(op=='D')
        {
            int k;
            cin>>k;
            if(!k) head = ne[head];
            del(k-1);
        }
    }
    for(int i=head;i!=-1;i=ne[i]) cout<<e[i]<<' ';
    return 0;
}
