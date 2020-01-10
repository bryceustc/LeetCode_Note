// C++ Solution 1:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res =0;
        unordered_map<int,int> map;
        int n=nums.size();
        for (int i=0;i<n;i++)
        {
            map[nums[i]]++;
        }
        for (int i=0;i<n;i++)
        {
            if (map[nums[i]]==1)
            {
                res = nums[i];
                break;
            }
        }
        return res;
    }
};



class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        unordered_set<int> st;
        for (int num : nums) 
        {
            if (st.find(num)!=st.end()) // if (st.count(num))
                st.erase(num);
            else 
                st.insert(num);
        }
        res = *st.begin();
        return res;
    }
};
// C++ Solution 2:
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        unordered_set<int> st;
        for (int num : nums) 
        {
            if (st.find(num)!=st.end()) // if (st.count(num))
                st.erase(num);
            else 
                st.insert(num);
        }
        res = *st.begin();
        return res;
    }
};
