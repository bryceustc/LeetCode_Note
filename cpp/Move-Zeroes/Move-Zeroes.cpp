// C++ Solution 1:
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()) return;
        vector<int> res;
        int n = nums.size();
        for (int i =0;i<n;i++)
        {
            if (nums[i]!=0)
              res.push_back(nums[i]);
        }
        for (int i =0;i<n;i++)
        {
            if (nums[i]==0)
              res.push_back(nums[i]);
        }
    }
};


// C++ Solution 2:
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()) return;
        int n = nums.size();
        for (int i =0;i<n;i++)
        {
            if (nums[i]==0)
            {
                for (int j=i+1;j<n;j++)
                {
                    if (nums[j]!=0)
                    {
                        int temp = nums[j];
                        for (int k=j;k>i;k--)
                        {
                            nums[k]=nums[k-1];
                        }
                        nums[i] = temp;
                        break;
                    }
                }
            }
        }    
    }
};

// C++ Solution 3:
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.empty()) return;
        int n = nums.size();
        for (int i =0;i<n;i++)
        {
            for (int j=n-1;j>i;j--)
            {
                if (nums[j]!=0 && nums[j-1]==0)
                {
                    swap(nums[j],nums[j-1]);
                }
            }
        }    
    }
};
