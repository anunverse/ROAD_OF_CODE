class Solution {
public:
    vector<string> res;
    string order;
    map<char, int> chosen;
    void calc(int x, string s)
    {
        if (x == s.size())
        {
            res.push_back(order);
            return ;
        }
        for (int i = 0; i < s.size(); i ++ )
        {
            if (chosen[s[i]]) continue;
            chosen[s[i]] = 1;
            order[x] = s[i];
            calc(x + 1, s);
            chosen[s[i]] = 0;
        }
    }
    vector<string> permutation(string S) {
        order = S;
        calc(0, S);
        return res;
    }
};
