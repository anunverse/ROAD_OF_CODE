// https://www.acwing.com/problem/content/description/138 

#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

typedef long long ll;
const int N = 100010;

struct Node{
    ll value;
    int prev, next;
}node[N];

int tot, head, tail, n;
pair<ll, int> a[N];
pair<ll, int> b[N];
pair<ll, int> ans[N];

void init()
{
    tot = 2;
    head = 1, tail = 2;
    node[head].next = tail;
    node[tail].prev = head;
}

void insert(int p, ll val)
{
    int q = ++tot;
    node[q].value = val;
    node[node[p].next].prev = q;
    node[q].next = node[p].next;
    node[p].next = q;
    node[q].prev = p;
}

void remove(int p)
{
    node[node[p].prev].next = node[p].next;
    node[node[p].next].prev = node[p].prev;
}

void show()
{
    int q = head;
    while (node[q].next != tail)
    {
        cout << node[node[q].next].value << ' ';
        //cout << node[q].next << ' ';
        q = node[q].next;
    } 
    cout << endl;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    init();
    node[head].value = 5e9;
    node[tail].value = -5e9;
    insert(head, a[1].first);
    b[a[1].second].first = 1;
    b[1].second = a[1].second;
    int k = 3;
    for (int i = 2; i <= n; i ++ )
    {
        insert(k++, a[i].first);
        b[a[i].second].first = i;
        b[i].second = a[i].second;
    }
    for (int i = n; i >= 2; i --)
    {
        ll v1 = abs(node[b[i].first + 2].value - node[node[b[i].first + 2].prev].value);
        ll v2 = abs(node[b[i].first + 2].value - node[node[b[i].first + 2].next].value);
        if (v1 <= v2)
        {
            ans[i].first = v1;
            ans[i].second = b[node[b[i].first + 2].prev - 2].second;
        }
        else
        {
            ans[i].first = v2;
            ans[i].second = b[node[b[i].first + 2].next - 2].second;
        }
        remove(b[i].first + 2);
    }
    for (int i = 2; i <= n; i ++ ) cout << ans[i].first << ' ' << ans[i].second << endl;
    return 0;
}
