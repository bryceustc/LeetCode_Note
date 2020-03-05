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
