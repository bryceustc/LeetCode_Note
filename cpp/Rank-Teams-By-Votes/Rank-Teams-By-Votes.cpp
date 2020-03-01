class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string res = votes[0];
        int n = votes[0].size();
        map<char, map<int, int>> m;
        for (auto s : votes)
        {
            for (int i=0;i<n;i++)
            {
                m[s[i]][i]++;
            }
        }
        // [&] 任何被使用到的外部变量都隐式地以引用方式加以引用。
        sort (res.begin(), res.end(), [&] (char a, char b)->bool
        {
            for (int i=0;i<n;i++)
            {
                if(m[a][i]  > m[b][i]) return true;
                if (m[a][i] < m[b][i]) return false;
            }
            return a<b;
        });
        return res;
    }
};
