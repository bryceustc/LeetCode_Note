/// Source : https://leetcode-cn.com/problems/reverse-integer/
/// Author : bryce
/// Time   : 2019-10-29
class Solution {
public:
    int reverse(int x) {
        long int res = 0;
        int m = - pow(2,31);
        int n = pow(2,31) - 1;
        int temp = x;
        int count = 0;
        long int i = 0, j = 0;
        
        while(temp) //获取位数
        {
            count++;
            temp /=10;
        }
        
        while(x)//计算每一位数字
        {
            i = x / pow(10,count-1);
            x = x - i*pow(10,count-1);
            res += i*pow(10,j);
            j++;
            count--;
        }
        
        if (res<m||res>n)
            res = 0;
        return res;
        
        
    }
};

class Solution2 {
public:
    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (res > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0; // 2^31-1 = 2147483647
            if (res < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;//2^31 = 2147483648
            res = res * 10 + pop;
        }
        return res;
    }
};

时间复杂度：O(log(x))
空间复杂度：O(1)


int main() {

    cout << Solution().reverse( 1534236469 )<<endl;
    return 0;
}
