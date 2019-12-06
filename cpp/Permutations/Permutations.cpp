
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) return res;
        vector<int> out;
        int n =nums.size();
        vector<int> visited(n,0);
        DFS(nums,0,visited,out,res);
        return res;
    }
    
    void DFS(vector<int>& nums, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res)
    {
        if (level == nums.size())
        {
            res.push_back(out);
            return;
        }
        for (int i=0; i<nums.size();i++)
        {
            if (visited[i] == 1)
                continue;
            visited[i] = 1;
            out.push_back(nums[i]);
            DFS(nums,level+1,visited,out,res);
            out.pop_back();
            visited[i] = 0;
        }        
    }
};
