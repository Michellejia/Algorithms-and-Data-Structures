#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int commonLength = 0;
        string commonString;
        int firstFlag = true;
        if (strs.size() == 1)
            return strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            int tmpLength = 0;
            for (int j = 0; j < min(strs[0].size(), strs[i].size()); j++)
            {
                if (strs[0][j] == strs[i][j])
                    tmpLength++;
                else
                    break;
            }
            if (firstFlag)
            {
                if (tmpLength > commonLength)
                    commonLength = tmpLength;
                firstFlag = false;
            }
            else
            {
                if (tmpLength < commonLength)
                    commonLength = tmpLength;
            }
        }
        if (commonLength == 0)
            return "";

        for (int k = 0; k < commonLength; k++)
            commonString.push_back(strs[0][k]);
        return commonString;
    }
};

int main()
{
    vector<string> s = {"a"};
    Solution res;
    printf("Longest common string: %s\n", res.longestCommonPrefix(s).c_str());
}