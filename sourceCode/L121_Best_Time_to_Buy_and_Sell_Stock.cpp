#include <vector>

#include <iostream>
using namespace std;

#include <algorithm>

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;

        for (int i = 0; i < prices.size() - 1; i++)
        {
            for (int j = i + 1; j < prices.size(); j++)
            {
                res = max(res, prices[j] - prices[i]);
            }
        }
        return res;
    }
};

int main()
{
    //largest difference doesn't mean first find the smallest one, and find the largest one later,
    //and the difference between the two is the largest. e.g: [2,5,1,3]
    vector<int> input = {7,1,5,3,6,4};
    Solution s;
    printf("%d\n", s.maxProfit(input));
}
