// C++ Solution 1:

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res={intervals[0]};
        for (int i=1;i<n;i++)
        {
            if (res.back()[1]<intervals[i][0])
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }
        }
        return res;
    }
};



// C++ Solution 2:
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        int n = intervals.size();
        vector<vector<int>> res;
        vector<int> starts,ends;
        for (int i=0;i<n;i++)
        {
            starts.push_back(intervals[i][0]);
            ends.push_back(intervals[i][1]);
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        for (int i=0,j=0;i<n;i++)
        {
            if (i==n-1||starts[i+1]>ends[i])
            {
                res.push_back({starts[j],ends[i]});
                j=i+1;
            }
        }
        return res;
    }
};
