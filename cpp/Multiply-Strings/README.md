# 题目描述: 字符串相乘(可实现大数相乘，超过int和long的限制)

给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

**示例 1:**
```
输入: num1 = "2", num2 = "3"
输出: "6"
```

**示例 2:**
```
输入: num1 = "123", num2 = "456"
输出: "56088"
```
  
# 解题思路:
  该算法是通过两数相乘时，乘数某位与被乘数某位相乘，与产生结果的位置的规律来完成。具体规律如下：
  
  - 乘数 ``num1`` 位数为 M，被乘数 ``num2`` 位数为 N， ``num1 x num2`` 结果 ``res`` 最大总位数为 M+N
  - ``num1[i] x num2[j]`` 的结果为 ``tmp``(位数为两位，"0x","xy"的形式)，其第一位位于 ``res[i+j]``，第二位位于 ``res[i+j+1]``。
  
  ![multiply](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Multiply-Strings/Image/multiply.png)

# 时间复杂度：
  时间复杂度：O(MN)。M,N 分别为 num1 和 num2 的长度。
  
# 空间复杂度
  O(M+N)。用于存储计算结果。
  
# 代码

## [C++](./Trapping-Rain-Water.cpp):
### 错误： 普通竖式法，未通过OJ，本质还是int乘法，
```c++
class Solution {
public:
    string multiply(string num1, string num2) {
        string res;
        if (num1 == "0"||num2 =="0") return "0";
        int n1 = num1.size();
        int n2 = num2.size();
        int carry = 0;
        int sum = 0;
        int sum_value = 0;
        for (int j = n2-1;j>=0;j--)
        {
            int temp = 0;
            for (int i = n1-1;i>=0;i--)
            {
                temp = (num2[j]-'0')*(num1[i]-'0')+carry;
                carry = temp / 10;
                sum += temp%10*(pow(10,n1-1-i));
                if (i==0 && carry!=0)
                {
                    sum += carry*(pow(10,n1));
                    carry = 0;
                }
            }
            sum_value += sum*(pow(10,n2-1-j));
            sum = 0;
        }
        res = to_string(sum_value);
        return res;
    }
};
```


### 方法一：优化竖式，
```c++
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();
        string res(n1+n2,'0');
        for(int i=n2-1;i>=0;i--)
        {
            for(int j=n1-1;j>=0;j--)
            {
                int temp=(res[i+j+1]-'0')+(num1[j]-'0')*(num2[i]-'0');
                res[i+j+1]=temp%10+'0';//当前位
                res[i+j]+=temp/10; //前一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0'
            }
        }
        
        //去除首位'0'
        for(int i=0;i<n1+n2;i++){
            if(res[i]!='0')
                return res.substr(i);
        }
        return "0";
    }
};
```


### 方法三： 动态规划
```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        if (height.empty()) return res;
        int n = height.size();
        vector<int> max_left(n,0);
        vector<int> max_right(n,0);
        for (int i = 1;i<n-1;i++)
        {
            max_left[i] = max(max_left[i-1],height[i-1]);
        }
        for (int i = n-2;i>=0;i--)
        {
            max_right[i] = max(max_right[i+1],height[i+1]);
        }
        
        for (int i=1;i<n-1;i++)
        {
            int min_height = min(max_left[i],max_right[i]);
            if (min_height > height[i])
                res += min_height-height[i];
        }
        return res;
    }
};
```

### 方法四： 双指针
```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int left = 1,right=n-2;
        int max_left=0,max_right=0;
        while (left <= right)
        {
          if (height[left-1] < height[right+1])
          {
              max_left = max(max_left,height[left-1]);
              int min_height = max_left;
              if (min_height > height[left])
                  res += min_height - height[left];
              left++;
          }
          else
          {
              max_right = max(max_right,height[right+1]);
              int min_height = max_right;
              if (min_height > height[right])
                  res += min_height - height[right];
              right--;
          }
        }
        return res;
    }
};
```


## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Trapping-Rain-Water/Trapping-Rain-Water.py)
### 方法一： HashSet法
```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n =len(nums)
        res = 1
        record = {}
        for index, num in enumerate (nums):
            record[num] = index
        for i in range (n):
            if res not in record:
                return res
            else:
                res+=1
        return res
```

### 方法二：交换位置法
```python
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while nums[i]<=n and nums[i]>0 and nums[i]!=nums[nums[i]-1]:
                temp = nums[i]
                nums[i] = nums[temp-1]
                nums[temp-1] = temp
        for i in range(n):
            if nums[i]!=i+1:
                return i+1
        return n+1
```
# 参考
  - [C++中map，hash_map,unordered_map,unordered_set区别与联系](https://blog.csdn.net/u013195320/article/details/23046305)
  - [数组中重复的数字](https://github.com/bryceustc/CodingInterviews/blob/master/DuplicationInArray/README.md)
