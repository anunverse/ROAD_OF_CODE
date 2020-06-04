https://www.acwing.com/problem/content/134/

#include <iostream>
#include <queue>
#include <map>
using namespace std;

const int N = 1010;
map<int, int> b;
int n, k;

int main()
{
    while(cin >> n && n)
    {
        k ++;
        cout << "Scenario #" << k <<endl;
        queue<int> dui;
        queue<int> zu[N];
        for (int i = 0; i < n; i ++ )
        {
            int nums; //人数
            cin >> nums;
            for (int j = 0; j < nums; j ++ )
            {
                int hao;
                cin >> hao;
                b[hao] = i + 1;
            }
        }
        string c;
        while (cin >> c && c != "STOP")
        {
            if (c == "ENQUEUE")
            {
                int bianhao;
                cin >> bianhao;
                if (zu[b[bianhao]].empty()) dui.push(b[bianhao]);
                zu[b[bianhao]].push(bianhao);
            }
            if (c == "DEQUEUE")
            {
                int xu = dui.front();
                cout << zu[xu].front() << endl;
                zu[xu].pop();
                if (zu[xu].empty()) dui.pop();
            }
        }
        cout << endl;
    }
    return 0;
}
