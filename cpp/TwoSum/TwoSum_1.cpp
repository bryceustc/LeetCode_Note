#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
        vector<int> twoSum(vector<int> & nums, int target){
              vector<int> result;
               for( int i=0; i < nums.size(); i++)
                    for( int j=i+1; j < nums.size(); j++)
                        if ( nums[i] + nums[j] == target)
                        {
                        result.push_back(i);
                        result.push_back(j);
                        return result;
                        }
               throw invalid_argument("the input has no solution");
               return result;
}    
};

void  printVec (const vector<int> & vec) {
    for (int e : vec)
        cout << e << " ";
    cout << endl;
}

int main{
    vector < int > nums = { 2,7,11,15 };
    int target = 9 ;
    printVec ( Solution( ).twoSum(nums, target ) );
    return 0;
}
