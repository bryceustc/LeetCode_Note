# 题目描述:  第k个排列

给出集合 ``[1,2,3,…,n]``，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

 1. "123"
 
 2. "132"

 3. "213"

 4. "231"
 
 5. "312"
 
 6. "321"
 
给定 n 和 k，返回第 k 个排列。

**说明：**

 - 给定 n 的范围是 [1, 9]。
 - 给定 k 的范围是[1,  n!]。


**示例 1:**
```
输入: n = 3, k = 3
输出: "213"
```

**示例 2:**
```
输入: n = 4, k = 9
输出: "2314"
```

  
# 解题思路:
思路一：此题与[第46题全排列](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Permutations/README.md)类似，可以使用递归回溯（深度优先遍历）找出所有的全排列，然后找第k个排列，并转换为字符串，i+'0'。

思路二：回溯+剪枝
 
# 时间复杂度：
  思路一：搜索树中最后一层共 n!个叶节点，在叶节点处记录方案的计算量是 O(n)，所以叶节点处的计算量是 O(n×n!)。
搜索树一共有 n!+n!/2!+n!/3!+…=n!(1+1/2!+1/3!+…)≤n!(1+1/2+1/4+1/8+…)=2n!个内部节点，在每个内部节点内均会for循环 n次，因此内部节点的计算量也是 O(n×n!)。 所以总时间复杂度是 O(n×n!)。

  思路二：
# 空间复杂度
  思路一：O(n!) 由于必须要保存n! 个解。
  
  思路二：
  
# 代码

## [C++](./Permutation-Sequence.cpp):

###  方法一： 回溯全排列法（未通过OJ）
```c++
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> nums;
        vector<vector<int>> ans;
        vector<int> out;
        if (n<=0 || n>9 || k<=0) return res;
        for (int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        vector<int> visited(n+1,0);
        DFS(n,0,visited,ans,out);
        for (int i=0;i<ans[k-1].size();i++)
        {
            res+='0'+ans[k-1][i];
        }
        return res;
    }

    void DFS(int n,int level,vector<int> &visited, vector<vector<int>> &ans,vector<int> &out)
    {
        if (level==n)
        {
            ans.push_back(out);
            return;
        }
        for (int i=1;i<=n;i++)
        {
            if (visited[i]==1)
                continue;
            visited[i]=1;
            out.push_back(i);
            DFS(n,level+1,visited,ans,out);
            out.pop_back();
            visited[i]=0;
        }
    }
};
```

###  方法一改进版：回溯+剪枝+减去前k-1个枝（比较笨）
```c++
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        if (n<=0 || n>9 || k<=0) return res;
        vector<int> visited(n,0);
        vector<vector<int>> ans;
        vector<int> out;
        vector<int> nums; 
        for (int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        DFS(nums,0,visited,out,ans,k);
       
        for(int i=0;i<ans[0].size();i++)
        {
            res+='0'+ans[0][i];
        }
        return res;
    }

    int factorial(int num)   // 阶乘
    {
        int res = 1;
        while(num>0)
        {
            res*=num;
            num--;
        }
        return res;
    }

    void DFS(vector<int> nums, int level, vector<int> &visited, vector<int> &out, vector<vector<int>> & ans,int k)
    {
        int n =nums.size();
        if (level==n)
        {
            ans.push_back(out);
            return;
        }
        int ps = factorial(n-1-level);  // 求出这一个分支将要产生的叶子结点数 n-1-level的阶乘
        for (int i=0;i<n;i++)
        {
            if (visited[i]==1)
            {
                continue;
            }
            if (ps >0 && ps<k)   // 如果k>这一分支要产生的叶子结点数，就进行剪枝
            {
                k-=ps;
                continue;
            }
            visited[i]=1;
            out.push_back(nums[i]);
            DFS(nums,level+1,visited,out,ans,k);
            out.pop_back();
            visited[i]=0;
        }
    }
};
```




## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Permutation-Sequence/Permutation-Sequence.py)
###  方法一：回溯全排列
```python
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0]* n for _ in range(n)]    ##python初始化二维数组
        out = [i for i in range(n*n,0,-1)]
        u = 0
        d = n-1
        l = 0
        r = n-1
        while True:  ## 可以改为while num<=pow(n,2): 更节省时间
            for i in range(l,r+1,1):
                res[u][i] = out[-1]
                #del out[-1]
                out.pop()
            u+=1
            if u>d:break
            for i in range(u,d+1,1):
                res[i][r] = out[-1]
                del out[-1]
            r-=1
            if r<l:break
            for i in range(r,l-1,-1):
                res[d][i] = out[-1]
                del out[-1]
            d-=1
            if d<u:break
            for i in range(d,u-1,-1):
                res[i][l]=out[-1]
                del out[-1]
            l+=1
            if l>r:break
        return res
```

###  方法一：改进版——回溯+剪枝
```python
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        res = [[0]* n for _ in range(n)]    ##python初始化二维数组
        # res = [[0 for _ in range(n)] for _ in range(n)]
        u = 0
        d = n-1
        l = 0
        r = n-1
        m = pow(n,2)
        num = 1
        while num<=m:
            for i in range(l,r+1,1):
                res[u][i] = num
                num+=1
            u+=1
            for i in range(u,d+1,1):
                res[i][r] = num
                num+=1
            r-=1
            for i in range(r,l-1,-1):
                res[d][i] = num
                num+=1
            d-=1
            for i in range(d,u-1,-1):
                res[i][l]=num
                num+=1
            l+=1
        return res
```


# 参考

  -  [46题全排列](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Permutations/README.md)
  -  [47题全排列II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Permutations-II/README.md)
  -  [回溯+剪枝](https://leetcode-cn.com/problems/permutation-sequence/solution/hui-su-jian-zhi-python-dai-ma-java-dai-ma-by-liwei/)

