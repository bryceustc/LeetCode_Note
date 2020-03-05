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

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n = num_people;
        // how many people received complete gifts
        int p = (int)(sqrt(2 * candies + 0.25) - 0.5);
        int remaining = (int)(candies - (p + 1) * p * 0.5);
        int rows = p / n, cols = p % n;

        vector<int> d(n, 0);
        for (int i = 0; i < n; ++i) {
            // complete rows
            d[i] = (i + 1) * rows + (int)(rows * (rows - 1) * 0.5) * n;
            // cols in the last row
            if (i < cols) d[i] += i + 1 + rows * n;
        }
        // remaining candies 
        d[cols] += remaining;
        return d;
    }
};
