#include <iostream>
#include <vector>
#include <cassert>
#include <tr1/unordered_map>
 
using namespace std;
using namespace std::tr1;
 
/// One-Pass Hash Table
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
 
        unordered_map<int,int> record;
        vector<int> result;
        for(int i = 0 ; i < nums.size() ; i++){
 
            int complement = target - nums[i];
            if(record.find(complement) != record.end()){                  //find函数找到元素就不会返回record.end() 没找到就会返回，这里判断是如果找到了
                result.push_back(record[complement]);
                result.push_back(i);

            }
            record[nums[i]] = i;
        }
 
        //throw invalid_argument("the input has no solution");
        return result;
    }
};
 
 
void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}
 
int main() {
 
    const int nums[] = {2,7,11,15};
    vector<int> nums_vec( nums, nums + sizeof(nums)/sizeof(int) );
    int target = 9;
    printVec(Solution().twoSum(nums_vec, target));
 
    return 0;
}
}
