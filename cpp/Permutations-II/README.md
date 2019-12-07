class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        int n = nums.size();
        vector<int> visited (n,0);
        if (nums.empty())
            return res;
        sort(nums.begin(),nums.end());
        DFS(nums,0,visited,out,res);
        return res;
    }
    void DFS(vector<int>& nums, int level, vector<int>& visited, vector<int>& out, vector<vector<int>>& res)
    {
        int n = nums.size();
        if (level==n)
        {
            res.push_back(out);
            return;
        }
            
        for (int i=0;i<n;i++)
        {
            if (i>0 && nums[i]==nums[i-1] && visited[i-1]==0) //判断num[i]==nums[i-1]前提是有序，相同的数字才回相邻
                continue;
            if (visited[i]==1)
                continue;
            visited[i]=1;
            out.push_back(nums[i]);
            DFS(nums,level+1,visited, out, res);
            out.pop_back();
            visited[i]=0;
        }
    }
};
