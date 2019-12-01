/// Source : https://leetcode-cn.com/problems/combination-sum/
/// Author : bryce
/// Time   : 2019-11-30


#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
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
            out.push_back(candidates[i]);
            DFS(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
};

int main()
{
    int target = 7;
    vector<int> candidates = {2,3,6,7};
    vector<vector<int>> res = Solution().combinationSum(candidates,target);
    cout << res[0][0]<<endl;
    system("pause");
    return 0;
}
