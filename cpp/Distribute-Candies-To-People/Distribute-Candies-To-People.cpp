class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people,0);
        int i =0;
        while (candies>i)
        {
            res[i%num_people] +=  i+1;
            candies-=i+1;
            i++;
        }
        res[i%num_people] += candies;
        return res;
    }
};
