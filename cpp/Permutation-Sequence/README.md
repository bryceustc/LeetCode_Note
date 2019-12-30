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

思路二：（回溯）+剪枝，因为是一次递归直接到叶子，所以不需要还原状态，也就是说不需要回溯重置状态，一次递归到底就能找到 第 k 个排列

思路三：使用数学方法，康托展开
 
# 时间复杂度：
  思路一：搜索树中最后一层共 n!个叶节点，在叶节点处记录方案的计算量是 O(n)，所以叶节点处的计算量是 O(n×n!)。
搜索树一共有 n!+n!/2!+n!/3!+…=n!(1+1/2!+1/3!+…)≤n!(1+1/2+1/4+1/8+…)=2n!个内部节点，在每个内部节点内均会for循环 n次，因此内部节点的计算量也是 O(n×n!)。 所以总时间复杂度是 O(n×n!)。

  思路二：O(n<sup>2</sup>) 这里递归次数为N，且在递归函数里的for循环里，只会发生一次递归（不符合条件的不递归，也就是剪枝），for循环每次最多循环N遍（k=n! 就是这种情况），最少循环N-depth（depth为递归的深度，k=1就是这种情况），所以最坏时间复杂度为：N+N+....+N=O(N的平方)，最好时间复杂度为：N+N-1+...+1=N*(N+1)/2=O(N的平方），因此，时间复杂度应该是O(N的平方）才对吧。

  思路三：使用数学方法，康托展开
# 空间复杂度
  思路一：O(n!) 由于必须要保存n! 个解。
  
  思路二：O(n)
  
  
  
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
    // 求 n 的阶乘 或者直接使用数组：factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}
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
###  方法一改进版：(回溯)+剪枝+减去前k-1个枝（因为是一次递归直接到叶子，所以不需要还原状态）
```c++
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<int> visited(n,0);
        vector<int> out;
        vector<int> nums; 
        for (int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        DFS(nums,0,visited,out,k);
        for (int i=0;i<n;i++)
        {
           res+=out[i]+'0';
        }
         return res;
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

    void DFS(vector<int> nums, int level, vector<int> &visited, vector<int> &out,int k)
    {
        int n =nums.size();
        if (level==n)
        {
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
            DFS(nums,level+1,visited,out,k);// 因为是一次递归直接到叶子，所以不需要还原状态
            //out.pop_back();
            //visited[i]=0;
        }
    }
};
```
###  方法一完善版：(回溯)+剪枝+减去前k-1个枝（因为是一次递归直接到叶子，所以不需要还原状态）
```c++
class Solution {
public:
    // 方法1：使用回溯法的思路思考，则每当选择一个数加入排列时，可以计算出剩下的数还有多少种排列的可能，
    // 即可以计算出当前被选择的数的排列总数，设用 remain_fac 表示， remain_fac = 剩下的待选择的数的阶乘。
    // 然后将 remain_fac 与 k 进行大小比较，若小于 k ，则说明所要求的第 k 个排列不在以 当前选定的数 为开头的所有排列中，直接跳过
    // 一次递归到底就能找到 第 k 个排列
    string getPermutation(int n, int k) {
        vector<bool> visited(n + 1, false);          // 用于标记每个数是否用过
        string res;                            // 用于返回的结果排列序列
        DFS(visited, 0,res, n, k);
        return res;
    }
    // 递归实现
    void DFS(vector<bool> &visited,int level, string &res, int n, int k){
        if(level == n) // 结束条件，当前排列已经结束
        {   
            return;
        }
        int remain_fac = factorial(n - level - 1);  // 剩下的数的全排列的个数
        for(int i = 1; i <= n; i++){                  // 遍历 [1, n]
            if(visited[i])// 跳过已使用的数
            {                            
                continue;
            }
            if(remain_fac > 0 && remain_fac < k){     // 剩下的数的全排列个数小于当前 k ，说明第 k 个排列肯定不在当前的递归子树中，直接跳过该递归
                k -= remain_fac;                      // 剪枝
                continue;
            }
            res += '0' + i;
            visited[i] = true;
            DFS(visited,level+1, res, n, k);
                                                      // 因为是一次递归直接到叶子，所以不需要还原状态
        }
    }
    // 求 n 的阶乘 或者直接使用数组：factorial = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}
    int factorial(int n){
        int res = 1;
        while(n > 0){
            res *= n;
            n--;
        }
        return res;
    }
};
```

### 方法二：康托展开（数学方法）
```c++
class Solution {
public:
	string getPermutation(int n, int k) {
		string nums = "123456789";
		const vector<int> factor={1,1,2,6,24,120,720,5040,40320,362880};
        // 阶乘实现
        // vector<int> factor(1,1);
        // for (int i=1;i<=n;i++)
        // {
        //     factor.push_back(factor.back()*i);
        // }
		string res;
        while(n>0)
        {
            // 用3/2!=1余1,说明比首位小的数有1个，所以首位为2
            // 用1/1!=1余0，说明比第二位小的数有1个，所以第二位为1
            // 最后一位自然就是剩下3，所以n=3,k=3的排列组合是213
            int i = (k-1)/factor[n-1];          // -1是保证位数准确             
            res+=nums[i];
            nums.erase(nums.begin()+i);
            k-=i*factor[n-1];   // 注意取余的,用减法不用%取余符号，用k %=factor[n-1];会取到负数
            n--;
        }
		return res;
	}
};
```



## [Python:](https://github.com/bryceustc/LeetCode_Note/blob/master/python/Permutation-Sequence/Permutation-Sequence.py)
###  方法一：（回溯）+剪枝
```python
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        res = []   ## list的形式
        if n==0 :
            return ""  ##[]和""一样都表示为空
        visited = [0 for _ in range(n+1)]
        self.DFS(visited,0,res,n,k)
        res = ''.join(res)
        return res
    def DFS(self,visited,level,res,n,k):
        if level==n:
            return
        remain_fac = self.factorial(n-1-level)
        for i in range(1,n+1):
            if visited[i]==1:
                continue
            if remain_fac > 0 and remain_fac < k:
                k-=remain_fac
                continue
            res+=(str(i))   // 字符串的拼接
            visited[i]=1
            self.DFS(visited,level+1,res,n,k)
    def factorial(self,num):   // 阶乘
        res = 1
        while num>0:
            res*=num
            num-=1
        return res
```
 
### 方法一：res=''初始化的问题,res得声明为全局变量  
```python
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        res = ''

        def factorial(num):
            res = 1
            while num > 0:
                res *= num
                num -= 1
            return res

        def DFS(visited, level, n, k, res):
            if level == n:
                return res
            ps = factorial(n - 1 - level)
            for i in range(1, n + 1):
                if visited[i] == 1:
                    continue
                if 0 < ps < k:
                    k -= ps
                    continue
                res += str(i)  ## 递归到底时已经是第 k 个排列，res 也是字符串的形式
                visited[i] = 1
                return DFS(visited, level + 1, n, k, res)

        if n == 0:
            return ""
        visited = [0 for _ in range(n + 1)]
        res = DFS(visited, 0, n, k, res)
        return res
```


###  方法二：康托展开(数学方法)
```python
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        nums = [*map(str, range(1, 10))]  ## 参数前加一个星号，表明将所有的值放在同一个元组中，该参数的返回值是一个元组。
                                          ## 参数前加两个星号，表明将所有的值放在同一个字典中，该参数的返回值是一个字典。
        # print(nums)
        # ['1', '2', '3', '4', '5', '6', '7', '8', '9']
        factorial=[1]
        for i in range(1,n+1):
            factorial.append(factorial[-1]*i)
        res=""
        while n>0:
            i = (k-1)//factorial[n-1]
            res+=nums[i]
            nums.pop(i)
            k-=i*factorial[n-1]
            n-=1
        return res
```



# 参考

  -  [46题全排列](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Permutations/README.md)
  -  [47题全排列II](https://github.com/bryceustc/LeetCode_Note/blob/master/cpp/Permutations-II/README.md)
  -  [回溯+剪枝](https://leetcode-cn.com/problems/permutation-sequence/solution/hui-su-jian-zhi-python-dai-ma-java-dai-ma-by-liwei/)
  -  [Python合并list为字符串的方法](https://blog.csdn.net/Zx_whu/article/details/61926655)
  -  [Python字符串拼接总结](https://segmentfault.com/a/1190000015475309)
  -  [Python中的NULL和None](https://blog.csdn.net/songyunli1111/article/details/75145533)但python是把0，空字符串‘ ’，空列表[]和None都看作False，把其他数值和非空字符串都看作True
  -  [康托展开](https://baike.baidu.com/item/%E5%BA%B7%E6%89%98%E5%B1%95%E5%BC%80) 
  -  [Python3：可变对象和不可变对象](https://blog.csdn.net/Artprog/article/details/88732987) 
  -  [Python map() 函数](https://www.runoob.com/python/python-func-map.html) 
