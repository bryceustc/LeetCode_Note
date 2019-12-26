// C++ Solution 1:
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        if (nums.empty() || k>n) return res;
        sort(nums.begin(),nums.end());
        res = nums[n-k];
        return res;        
    }
};

// C++ Solution 2:
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        if (nums.empty() || k>n) return res;
        priority_queue<int, vector<int>,greater<int>> q;
        for (auto num:nums)
        {
            q.push(num);
            if (q.size()>k)
            {
                q.pop();
            }
        }
        res = q.top();
        return res;        
    }
};

// C++ Solution 3:
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        if (nums.empty() || k>n) return res;
        int start = 0;
        int end = n -1;
        int index = Partition(nums,start,end);
        while(index!=n-k)
        {
            if (index>n-k)
            {
                end = index - 1;
                index = Partition(nums,start,end);
            }
            else
            {
                start = index+1;
                index = Partition(nums,start,end);
            }
        }
        res = nums[n-k];
        return res;        
    }
    int Partition(vector<int> &nums,int start,int end){
        int index = start + rand()%(end-start+1);
        int pivot = nums[index];
        swap(nums[index],nums[start]);
        while (start < end)
        {
            while(start < end && nums[end]>=pivot)
            {
                end--;
            }
            nums[start] = nums[end];
            while(start < end && nums[start]<pivot)
            {
                start++;
            }
            nums[end] = nums[start];
        }
        nums[start] = pivot;   // 基准值归位
        return start;
    }
    
    int Partition (vector<int> &nums,int start,int end){
        int index = start + rand()%(end-start+1) ;
        int pivot = nums[index];
        swap(nums[index],nums[start];
        int pos = start;
        for (int i=start+1;i<=end;i++)
        {
            if (nums[i]<pivot)
            {
                pos++;
                if (i!=pos)
                {
                    swap(nums[pos],nums[i]);
                }
            }
        }
        swap(nums[pos],nums[start]);
        return pos;
    }
};
