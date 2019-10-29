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
    public int reverse(int x) {
        long temp = 0;
       
        while(x != 0){
            int pop = x % 10;
            temp = temp * 10 + pop;
            
            if(temp > Integer.MAX_VALUE || temp < Integer.MIN_VALUE){
                return 0;
            }
            x /= 10;
        }
        return (int)temp;
    }
}

int main() {

    cout << Solution().reverse( 1534236469 )<<endl;
    return 0;
}
