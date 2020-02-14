class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int m = popped.size();
        if (n!=m) return false;
        stack<int> s;
        int index = 0;
        for (int i=0;i<n;i++)
        {
            s.push(pushed[i]);
            while(!s.empty() && s.top()==popped[index])
            {
                s.pop();
                index++;
            }
        }
        return s.empty();
    }
};
