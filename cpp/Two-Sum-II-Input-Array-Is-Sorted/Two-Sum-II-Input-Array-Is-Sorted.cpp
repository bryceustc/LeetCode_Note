// C++ Solution 1:\
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> res (2,0);
        if (numbers.empty())
            return res;
        int n = numbers.size();
        for (int i=0;i<n;i++)
        {
            for (int j = i+1; j<n;j++)
            {
                if (numbers[i]+numbers[j]==target)
                {
                    res[0] = numbers[i];
                    res[1] = numbers[j];
                    break;
                }
            }
        }
        return res;
    }
};
// C++ Solution 2:
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector <int> res (2,0);
        if (numbers.empty())
            return res;
        int n = numbers.size();
        unordered_map<int,int> record;
        for (int i=0;i<n;i++)
        {
            int complement = target -numbers[i];
            if (record.find(complement)!=record.end())
            {
                res[0] = complement;
                res[1] = nums[i];
                break;
            }
            record[numbers[i]] = i;
        }
        return res;
    }
};
// C++ Solution 3:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> res (2,0);
        if (nums.empty())
            return res;
        int n = nums.size();
        int left = 0;
        int right = n-1;
        while (right>left)
        {
            if (nums[left]+nums[right]==target)
            {
                res[0] = nums[left];
                res[1] = nums[right];
                break;
            }
            if (nums[left]+nums[right]>target)
            {
                right--;
            }
            if (nums[left]+nums[right]<target)
            {
                left++;
            }
        }
        return res;
    }
};
