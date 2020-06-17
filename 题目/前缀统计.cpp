// https://www.acwing.com/problem/content/144/
#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 1000010;
int trie[SIZE][26], tot = 1;
int cnt[SIZE];
int N, M;

void insert(char *str)
{
    int len = strlen(str), p = 1;
    for (int k = 0; k < len; k ++ )
    {
        int ch = str[k] - 'a';
        if (trie[p][ch] == 0) trie[p][ch] = ++ tot;
        p = trie[p][ch];
    }
    cnt[p] ++;
}

int search(char *str)
{
    int res = 0;
    int len = strlen(str), p = 1;
    for (int k = 0; k < len; k ++ )
    {
        p = trie[p][str[k] - 'a'];
        res += cnt[p];
    }
    return res;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i ++ )
    {
        char a[SIZE];
        cin >> a;
        insert(a);
    }
    for (int j = 0; j < M; j ++ )
    {
        char b[SIZE];
        cin >> b;
        cout << search(b) << endl;
    }
    
    return 0;
}
