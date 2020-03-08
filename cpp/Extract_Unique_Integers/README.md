# 题目:提取不重复的整数

## 题目描述：
输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。

**输人描述：**
```
输入一个int型整数
```

**输出描述：**
```
按照从右向左的阅读顺序，返回一个不含重复数字的新的整数
```
**示例：**
```
输入：

9876673

输出：

37689
  ```
  
# 解题思路:
创建一个数组类似哈希

# 时间复杂度：
O(1)
# 空间复杂度
 O(n)
# 代码

[C++](./Extract_Unique_Integers.cpp)
# C++: 
###  
```c++
#include <stdio.h>
int main()
{
    int input;
    scanf("%d", &input);
    int res = 0;
    int m[10] = {0};
    int n = 0;
    while(input)
    {
        n = input%10;
        if (m[n]==0)
        {
            m[n]++;
            res = res*10 + n;
        }
        input/=10;
    }
    printf("%d",res);
    return 0;
}
```

### set
```c++
#include <stdio.h>
#include <set>
#include <string>
using namespace std;
int main()
{
  int input;
  scanf("%d",&input);
  string str = to_string(input);
  string res = "";
  set<char> s;
  int n = str.size();
  for (int i=n-1;i>=0;i--)
  {
    if (s.count(str[i])==0)
    {
      res+=str[i];
      s.insert(str[i]);
    }
  }
  int out = stoi(res);
  printf("%d", out);
  return 0;
}
```
