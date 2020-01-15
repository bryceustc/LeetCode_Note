class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        int n = hand.size();
        if (n%W!=0 || W<1 || W>n || hand.empty())
            return false;
        map<int, int> m;   // 有序哈希表
        for (auto card : hand)  
            m[card]++;
        while (!m.empty()) 
        {
            int start = m.begin()->first;// map 返回开始的关键值，也就是card的值
            for (int i = 0; i < W;i++) 
            {
                if (m.find(start + i)==m.end())  // 寻找start开始后的w个序列
                    return false;
                m[start+i]--;
                if (m[start + i] == 0) // 每找到一个满足的数字就删除
                    m.erase(start + i);
            }
        }
        return true;
    }
};
