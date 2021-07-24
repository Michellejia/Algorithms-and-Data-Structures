#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    // iterator
    std::vector<int> twoSum_v1(std::vector<int> &num, int target)
    {
        std::vector<int> output;
        for (auto it1 = num.begin(); it1 != num.end(); it1++)
        {
            for (auto it2 = it1 + 1; it2 != num.end(); it2++)
            {
                if (*it1 + *it2 == target)
                {
                    output.push_back(it1 - num.begin());
                    output.push_back(it2 - num.begin());
                    return output;
                }
            }
        }
        return output;
    }

    // length
    std::vector<int> twoSum_v2(std::vector<int> &num, int target)
    {
        std::vector<int> output;
        int length = num.size();
        for (int i = 0; i < length; i++)
        {
            for (int i1 = i + 1; i1 < length; i1++)
            {
                if (num[i] + num[i1] == target)
                {
                    output.push_back(i);
                    output.push_back(i1);
                    return output;
                }
            }
        }
        return output;
    }

    // hashTable
    std::vector<int> twoSum_v3(std::vector<int> &num, int target)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < num.size(); i++)
        {
            if (mp.find(target - num[i]) != mp.end())
                return {mp[target - num[i]], i};
                // equal to return {i, mp.find(target - num[i])->second};
            mp[num[i]] = i;
        }
        return {};
    }
};

int main()
{
    Solution s;
    std::vector<int> num = {3,3};
    int target = 6;
    std::vector<int> output = s.twoSum_v3(num, target);
    for (auto &i : output)
    {
        std::cout << i << endl;
    }
}
