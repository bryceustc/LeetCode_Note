class Solution {
public:
    bool rotateString(string A, string B) {
        int n = A.size();
        int m = B.size();
        bool res = false;
        if (n!=m) return res;
        if (A.empty()&&B.empty()) return true;
        for (int i=0;i<n;i++)
        {
            leftmove(A);
            if (!A.compare(B))
            {
                res = true;
                return res;
            }
        }
        return res;
    }
    void leftmove(string &s)
    {
        int n = s.size();
        char temp;
        temp = s[0];
        for (int i=0;i<n;i++)
        {
            if (i!=n-1)
            {
                s[i] = s[i+1];
            }
            else
            {
                s[i] = temp;
            }
        }
    }
};
