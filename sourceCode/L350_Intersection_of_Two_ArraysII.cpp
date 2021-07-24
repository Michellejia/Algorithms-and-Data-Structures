#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        for (int i = 0; i < nums1.size(); i++)
        {
            if (mp1.find(nums1[i]) != mp1.end())
                mp1[nums1[i]]++;
            else
                mp1[nums1[i]] = 1;
        }
        for (int j = 0; j < nums2.size(); j++)
        {
            if (mp2.find(nums2[j]) != mp2.end())
                mp2[nums2[j]]++;
            else
                mp2[nums2[j]] = 1;
        }
        for (auto &iter: mp1)
        {
            if (mp2.find(iter.first) != mp2.end())
            {
                int commonNum = min(mp2[iter.first], mp1[iter.first]);
                for (int j = 0; j < commonNum; j++)
                    res.push_back(iter.first);
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    Solution s;
    vector<int> res = s.intersect(nums1, nums2);
    for (int i = 0; i < res.size(); i++)
    {
        printf("%d\n", res[i]);
    }
}