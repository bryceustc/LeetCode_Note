碰到括号的问题首先想到栈
```c++
//
//  main.cpp
//  helloworld
//
//  Created by zhangdingyuan on 2020/5/7.
//  Copyright © 2020 kuaishou. All rights reserved.
//

//#include <iostream>
//using namespace std;
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    string res;
//    static int a;
//    res = 1 + '0';
//    std::cout << "Hello, World!\n"<<std::endl;
//    cout << res << endl;
//    system("pause");
//    return 0;
//}

#include<vector>
#include<iostream>
#include<map>
#include<stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string res;
        int multi = 0;
        stack<string> stk_res;
        stack<int> stk_multi;
        for (char & c : s) {
            if (c == '['){
                stk_res.push(res);
                stk_multi.push(multi);
                res="";
                multi=0;
            }
            else if (c == ']'){
                string tmp;
                string las_res = stk_res.top();
                int cur_multi = stk_multi.top();
                stk_res.pop();
                stk_multi.pop();
                for (int i = 0; i <cur_multi;++i){
                    tmp += res;
                }
                res = las_res + tmp;
            }
            else if (c>='0' && c<='9'){
                multi = multi * 10 + (c - '0'); //这种情况是避免出现12[c]这种，计算多位数的情况
            }
            else{
                res+=c;
            }
        }
        return res;
    }
};

int main() {
    string s = "3[a2[c]]4[b]";
    string res = Solution().decodeString(s);
    cout << res << endl;
    system("pause");
    return 0;
}

```
