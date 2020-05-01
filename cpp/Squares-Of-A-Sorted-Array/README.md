# 题目描述:  有序数组的平方

给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

**示例 :**
```
输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]
```

# 解题思路:
1： 自定义sort比较函数：

2：双指针:

 从后向前遍历，每次取left和right之中的绝对值较大者放进 res 的后面
 
# 时间复杂度：
  1: O(nlogn)
  
  2: O(n)
# 空间复杂度
  1: O(n)
  
  2: O(n)
# 代码
### 自定义sort
```c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res(A);
        sort(A.begin(),A.end(),cmp);
        for (int i=0;i<A.size();i++)
        {
            res[i]=A[i]*A[i];
        }
        return res;
    }
    static bool cmp(int a,int b)
    {
        int x = a>0?a:-a;
        int y = b>0?b:-b;
        return x<y;
    }
};
```
###  双指针
```c++
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> res(n);
        int i =n-1;
        int left = 0;
        int right = n-1;
        while(left<=right)
        {
            if (abs(A[left])<abs(A[right]))
            {
                res[i] = A[right]*A[right];
                i--;
                right--;
            }
            else
            {
                res[i] = A[left]*A[left];
                i--;
                left++;
            }
        }
        return res;
    }
};
```
