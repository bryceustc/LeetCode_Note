/// Source : https://leetcode-cn.com/problems/combination-sum-ii/
/// Author : bryce
/// Time   : 2019-12-1

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(),candidates.end());
        if (candidates.empty())
            return res;
        DFS(candidates, target, 0, out, res);
        return res;
    }
    
    void DFS(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res)
    {
        if (target < 0) return;
        if (target == 0)
        {
            res.push_back(out);
            return;
        }
        int n = candidates.size();
        for (int i = start; i<n; i++)
        {
            if (i>start && candidates[i] == candidates[i-1])
                continue;
            out.push_back(candidates[i]);
            DFS(candidates, target - candidates[i], i+1, out, res);
            out.pop_back();
        }
    }
};

int main()
{
    int target = 8;
    vector<int> candidates = {10,1,2,7,6,1,5}
    vector<vector<int>> res = Solution().combinationSum2(candidates,target);
    cout << res[0][0]<<endl;
    system("pause");
    return 0;
}
