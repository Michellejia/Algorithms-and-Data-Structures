#include <math.h>
#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int first = 0;
        int last = height.size() - 1;
        int maxWater = 0;
        int tmpWater;
        while (first < last)
        {
            int tmpWater = min(height[first], height[last]) * (last - first);
            if (tmpWater > maxWater)
                maxWater = tmpWater;

            if (height[first] > height[last])
                last--;
            else
                first++;
        }
        return maxWater;
    }
};

int main()
{
    vector<int> v = {1,2,1};
    Solution s;
    printf("Most Water: %d\n", s.maxArea(v));
}