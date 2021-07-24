#include <vector>
#include <iostream>
using namespace std;

#include <algorithm>

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxNumber = 0;
        // maxSub represents the max Number for the subarray whose max index is i
        // vector<int> maxSub;
        int maxSub = 0;
        int res = nums[0];

        if(nums.size() == 1)
            return nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            maxSub = maxNumber + nums[i];
            maxNumber = max(maxSub, nums[i]);
            res = max(res, maxNumber);
        }
        return res;
    }
};

int main(){
    vector<int> v = {5,4,-1,7,8};
    Solution s;
    printf("the longest substring sum is %d\n", s.maxSubArray(v));
}