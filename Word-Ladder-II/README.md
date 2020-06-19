```c++
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        if (n==0) return true;
        string temp;
        for (int i=0;i<n;i++) {
            if ((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || (s[i]>='0'&&s[i]<='9'))
            {
                temp+=s[i];
            }
        }
        cout << temp << endl;
        int i = 0;
        int m = temp.size();
        int j = m-1;
        while(i<j) {
            if (temp[i] == temp[j])
            {
                i++;
                j--;
            }
            else if((abs(temp[i]-temp[j])==32 ) && (temp[i]>'9')&& temp[j]>'9') {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
```
