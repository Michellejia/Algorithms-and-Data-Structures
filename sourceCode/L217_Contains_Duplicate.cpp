#include <vector>
#include <unordered_map>

#include <iostream>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if(mp[nums[i]] > 0)
                return true;
            else
                mp[nums[i]] = 1;
        }
        return false;
    }
};

int main(){
    vector<int> vec = {1,1,1,3,3,4,3,2,4,2};
    Solution s;
    printf("res: %s\n", s.containsDuplicate(vec));
}