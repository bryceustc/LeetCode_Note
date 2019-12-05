# 题目描述: 接雨水

给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

![rainwater](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Trapping-Rain-Water/Image/rainwatertrap.png)

上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

**示例 :**
```
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
```
  
# 解题思路:

  
  

# 时间复杂度：
  暴力遍历法：O(n<sup>2</sup>)
  动态规划：O(n)
  
  
# 空间复杂度
 暴力遍历法：O(1)
 动态规划：O(n)
  
# 代码

## [C++](./Trapping-Rain-Water.cpp):
### 方法一： 暴力遍历法：按行求
```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        if (height.empty()) return res;
        int n = height.size();
        int max_value = *max_element(height.begin(),height.end());    //找到vector数组中的最大值
        for (int i=1;i<=max_value;i++)
        {
            bool flag = false;     //标记是否开始更新 temp
            int temp = 0;
            for (int j=0;j<n;j++)
            {
                if (flag && height[j] < i)   
                {
                    temp++;
                }
                if (height[j] >= i)
                {
                    res += temp;
                    temp = 0;
                    flag = true;
                }
            }
        }
        return res;
    }
};
```


### 方法二： 暴力遍历法：按列求
```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        if (height.empty()) return res;
        int n = height.size();
        //因为两端不可能积雨水，下标从1到n-2
        for (int i =1; i<n-1; i++)
        {
            int max_left = 0;
            int max_right = 0;
            
            // 寻找左边最高
            for (int j = i-1;j>=0;j--)
            {
                if (height[j]>max_left)
                {
                    max_left = height[j];
                }
            }
            
            // 寻找右边最高
            for (int k =i+1;k<n;k++)
            {
                if (height[k] > max_right)
                {
                    max_right = height[k];
                }
            }
            
            int min_height = min(max_left,max_right);
            if ( min_height > height[i])
            {
                res += min_height - height[i];
            }
        }
        return res;
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

### 方法五： 栈

看到栈，就会向想到括号匹配。我们观察蓝色的部分，可以和括号匹配类比下。每次匹配出一对括号（找到对应的一堵墙），就计算这两堵墙中的水。

我们用栈保存每堵墙。

当遍历墙的高度的时候，如果当前高度小于栈顶的墙高度，说明这里会有积水，我们将墙的高度的下标入栈。

如果当前高度大于栈顶的墙的高度，说明之前的积水到这里停下，我们可以计算下有多少积水了。计算完，就把当前的墙继续入栈，作为新的积水的墙。

总体的原则就是，

   1. 当前高度小于等于栈顶高度，入栈，指针后移。
   
   2. 当前高度大于栈顶高度，出栈，计算出当前墙和栈顶的墙之间水的多少，然后计算当前的高度和新栈的高度的关系，重复第 2 步。直到当前墙的高度不大于栈顶高度或者栈空，然后把当前墙入栈，指针后移。
   
   ![1](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Trapping-Rain-Water/Image/1.png)

我们看具体的例子。

   - 首先将 ``height [ 0 ]`` 入栈。然后 ``current`` 指向的高度大于栈顶高度，所以把栈顶 ``height [ 0 ]`` 出栈，然后栈空了，再把 ``height [ 1 ]`` 入栈。current 后移。

  ![2](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Trapping-Rain-Water/Image/2.png)
  
  ![3](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Trapping-Rain-Water/Image/3.png)
  
  - 然后 ``current`` 指向的高度小于栈顶高度，``height [ 2 ]`` 入栈，``current`` 后移。
  
  ![4](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Trapping-Rain-Water/Image/4.png)
  
  - 然后 ``current`` 指向的高度大于栈顶高度，栈顶 ``height [ 2 ]`` 出栈。计算 ``height [ 3 ]`` 和新的栈顶之间的水。计算完之后继续判断 ``current`` 和新的栈顶的关系。
  
  ![5](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Trapping-Rain-Water/Image/5.png)
  
  - ``current`` 指向的高度大于栈顶高度，栈顶 ``height [ 1 ]`` 出栈，栈空。所以把 ``height [ 3 ]`` 入栈。``currtent`` 后移。
  
  ![6](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Trapping-Rain-Water/Image/6.png)
  
  - 然后 current 指向的高度小于栈顶 height [ 3 ] 的高度，height [ 4 ] 入栈。current 后移。
  
  ![7](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Trapping-Rain-Water/Image/7.png)
  
  - 然后 current 指向的高度小于栈顶 height [ 4 ] 的高度，height [ 5 ] 入栈。current 后移。
  
  ![8](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Trapping-Rain-Water/Image/8.png)
  
  - 然后 current 指向的高度大于栈顶 ``height [ 5 ]`` 的高度，将栈顶 ``height [ 5 ]`` 出栈，然后计算 ``current`` 指向的墙和新栈顶 ``height [ 4 ]`` 之间的水。计算完之后继续判断 ``current`` 的指向和新栈顶的关系。此时 ``height [ 6 ]`` 不大于栈顶 ``height [ 4 ]`` ，所以将 ``height [ 6 ]`` 入栈。``current`` 后移
  
  ![9](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Trapping-Rain-Water/Image/9.png)
  
  - 然后 current 指向的高度大于栈顶高度，将栈顶 ``height [ 6 ]`` 出栈。计算和新的栈顶 ``height [ 4 ]`` 组成两个边界中的水。然后判断 ``current`` 和新的栈顶 ``height [ 4 ]`` 的关系，依旧是大于，所以把 ``height [ 4 ]`` 出栈。计算 ``current`` 和 新的栈顶 ``height [ 3 ]`` 之间的水。然后判断 ``current`` 和新的栈顶 ``height [ 3 ]`` 的关系，依旧是大于，所以把 ``height [ 3 ]`` 出栈，栈空。将 ``current`` 指向的 ``height [ 7 ]`` 入栈。``current`` 后移。其实不停的出栈，可以看做是在找与 7 匹配的墙，也就是 3
  
  而对于计算 ``current`` 指向墙和新的栈顶之间的水，根据图的关系，我们可以直接把这两个墙当做之前方法三的 ``max_left`` 和 ``max_right``，然后之前弹出的栈顶当做每次遍历的 ``height [ i ]``。水量就是 ``Min ( max _ left ，max _ right ) - height [ i ]``，只不过这里需要乘上两个墙之间的距离。

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
### 方法一： 暴力求解法（未通过OJ,按列来求解,时间复杂度n<sup>2</sup>）
```python
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        res = 0
        if n==0:
          return res
        for i in range (1,n-1):
            max_left = 0
            max_right = 0
            for j in range (i-1,-1,-1):
                if height[j] > max_left:
                    max_left = height[j]
            for k in range (i+1,n,1):
                if height[k] > max_right:
                    max_right = height[k]
            min_height = min(max_left,max_right)
            if min_height > height[i]:
                res += min_height - height[i]
        return res
```

### 方法二：动态规划
```python
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n==0:
          return 0
        res = 0
        max_left = [0 for x in range(n)]
        max_right = [0 for y in range(n)]
        for i in range(1,n):
            max_left[i] = max(max_left[i-1],height[i-1])
        for j in range(n-2,-1,-1):
            max_right[j] = max(max_right[j+1],height[j+1])
        for i in range(1,n-1):
            min_height= min(max_left[i],max_right[i])
            if min_height > height[i]:
                res += min_height - height[i]
        return res
```

### 方法三：双指针
```python
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n==0:
          return 0
        res = 0
        max_left = 0
        max_right = 0
        left = 1
        right = n-2
        while right >= left:
            if height[left-1] < height[right+1]:
                max_left = max(max_left,height[left-1])
                min_height = max_left
                if min_height > height[left]:
                    res += min_height - height[left]    
                left += 1
            else:
                max_right = max(max_right,height[right+1])
                min_height = max_right
                if min_height > height[right]:
                    res += min_height - height[right] 
                right -= 1
        return res
```

# 参考
  - [接雨水思路分析](https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/)
