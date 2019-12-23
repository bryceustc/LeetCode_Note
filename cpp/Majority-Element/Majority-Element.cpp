 // C++ Solution 1:
class Solution{
    public:
        int majorityElement(vector<int>&nums)
        {
            int res = 0 ;
            if (nums.empty()) return res;
            int n = nums.size();
            int half = n/2;
            for (int i=0;i<n;i++)
            {
                int count = 0;
                for (auto num : nums)
                {
                    if (nums[i] == num)
                    {
                        count+=1;
                        if (count > half)
                        {
                            res = num;
                        }
                    }
                }
            }
            return res;          
        }
};



// C++ Solution 2:

class Solution{
    public:
        int majorityElement(vector<int>&nums)
        {
            int res =0;
            if (nums.empty()) return res;
            int n = nums.size();
            int half = n/2;
            unordered_map<int,int> record;
            for (auto num:nums)
            {
                record[num]++;
                if(record[num]>half)
                {
                    res = num;
                }
            }     
      
          
          
     // C++ Solution 3:
          class Solution{
    public:
        int majorityElement(vector<int>&nums)
        {
            int res = 0 ;
            if (nums.empty()) return res;
            int n = nums.size();
            int half = n/2;
            for (int i=0;i<n;i++)
            {
                int count = 0;
                for (auto num : nums)
                {
                    if (nums[i] == num)
                    {
                        count+=1;
                        if (count > half)
                        {
                            res = num;
                        }
                    }
                }
            }
            return res;          
        }
};
          
 // C++ Solution 4:
          class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        if (nums.empty()) return res;
        int n = nums.size();
        int half = n/2;
        sort(nums.begin(),nums.end());
        res = nums[half];
        return res;      
    }
};
