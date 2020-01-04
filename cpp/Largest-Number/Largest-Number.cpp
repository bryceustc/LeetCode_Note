class Solution{
    public:
        string largestNumber(vector<int>& nums)
        {
            string res;
            int n = nums.size();
            sort(nums.begin(),nums.end(),compare);  // compare 自定义比较规则，不设置默认是从小到大
            for (int i=0;i<n;i++)
            {
                res += to_string(nums[i]);
            }
            if (res[0] == '0') 
                return "0";
            else
                return res;          
        }
        // 需要加static
        // 原因：
        // 简单来讲，就是函数参数不匹配的问题。因为我们普通的成员函数都有一个隐含的this指针。
        // bool cmp( Solution* this, const Interval &a,const Interval &b );
        // 实际上cmp函数有三个参数，而我们调用sort()排序函数的时候只需要用到两个参数进行比较，所以就出现了形参与实参不匹配的情况
        //（函数有三个形参，但是只输入了两个实参）。
        static bool compare(int a, int b)
        {
            string sa = to_string(a);
            string sb = to_string(b);
            return (sa + sb) > (sb + sa);
            // 两个字符串自左向右逐个字符相比（按ASCII值大小相比较），直到出现不同的字符或遇’\0’为止。
            // 当两个数的位数一样，则直接可以应用字符串的比较。如 "1346" > "1111" == true
        }
};
