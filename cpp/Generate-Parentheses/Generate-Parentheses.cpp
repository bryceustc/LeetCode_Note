/// Source : https://leetcode-cn.com/problems/generate-parentheses/
/// Author : bryce
/// Time   : 2019-11-12

/*
思路:
 这种生成括号的规则，其实隐含了一条信息：那就是始终左括号的数量要大于或等于右括号的数量。也就是说，剩余的左括号的数量要始终小于等于右括号。左括号只要有，
 就可以打印；而只 有当剩余的右括号数量比左括号大时，才能打印右括号。为了方便理解，假设n = 2，那么根据刚才的隐含信息，逻辑应该是这样的：
 
1. 肯定要先取一个左括号，此时左括号剩余的数量变为1，右括号剩余数量还是2

2. 第二位取左括号也行，取右括号也行。如果取左括号，那么此时右括号剩余数量为2，左括号剩余数量为0，长成了这个样子"(("；如果取右括号，左右剩余数量都是1，
长成这个样子"()"

3. 第三位，如果剩余左括号没了，就只能跟进右括号了，连续两个，最终变成"(())"；而如果现在是"()"的，那么要先左后右，最终变成"()()".

发现，每一步都有两种选择：左或者右，当然不一定都可行，如果可行，那么往后继续，不可行，终止。

例如当n=2时，二叉树应该是这个样子:
  1:      (
        /   \
  2:   (      )    
      /  \   / \
  3:cut   ) (  cut
         / \ \
  4:    cut ) )
  
可以用DFS求解此题。
*/

// C++ Solution 1:
class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string> res;
      if (n==0) return res;
      DFS = (n,n,"",res);
      return res;
    }
    void( int l, int r, string out, vector<string> &res){   //res前记得加&符号，改变实参
      if (l==0 && r==0)      // 相当于节点为空，也就是深搜不能再深入了 
        res.push_back(out);
      if (l > 0) DFS(l-1,r,out+'(',res);  // 相当于左节点还存在
      if (r > l) DFS(l,r-1,out+')',res);  // 相当于右节点还存在
    }
    }
};
