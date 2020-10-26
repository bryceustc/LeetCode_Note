# 题目描述:  两次日期绝对值之差

请你编写一个程序来计算两个日期之间隔了多少天。

日期以字符串形式给出，格式为 YYYY-MM-DD，如示例所示。

**示例 1:**
```
输入：date1 = "2019-06-29", date2 = "2019-06-30"
输出：1
```
**示例 2:**
```
输入：date1 = "2020-01-15", date2 = "2019-12-31"
输出：15
```

**提示:** 

  - 给定的日期是 1971 年到 2100 年之间的有效日期。

# 解题思路:
模拟法

# 时间复杂度：
  O(n)
# 空间复杂度
  O(n)
  
# 代码

## [C++](./Number-Of-Days-Between-Two-Dates.cpp):
```c++
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(get(date1) - get(date2));  // 两次日期绝对值之差
    }
    bool is_leap(int year)
    {
        return year%100!=0 && year % 4==0 || year % 400==0;  // 闰年定义 
    }
    int get(string date)
    {
        int year, month, day;
        sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);  //sscanf() - 从一个字符串中读进与指定格式相符的数据.
        int m_days[13] = {0, 31, 28, 31,  30, 31, 30, 31, 31, 30, 31, 30, 31};
        int days = 0;
        for (int i=1971;i<year;i++)
        {
            days+=365+is_leap(i);
        }
        for (int i=1;i<month;i++)
        {
            if (i==2)  days+=28+is_leap(year);
            else
            {
                day+=m_days[i];
            }
        }
        return day + days;
    }
};
```

# 参考

  [scanf 用法及陷阱（转）](https://www.cnblogs.com/vanishfan/archive/2013/03/04/2942492.html)
  [C语言函数sscanf()的用法](https://www.cnblogs.com/lyq105/archive/2009/11/28/1612677.html)
  [C++中c_str()函数的用法](https://blog.csdn.net/JIEJINQUANIL/article/details/51547027)

