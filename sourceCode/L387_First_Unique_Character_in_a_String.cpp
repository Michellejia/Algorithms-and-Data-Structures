#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution
{
public:
    int firstUniqChar_v1(string s)
    {
        // mp represents the times each character exits
        // mp_index represents the latest index for each character
        unordered_map<char, int> mp;
        unordered_map<char, int> mp_index;
        int smallestIndex = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            mp_index[s[i]] = i;
            if (mp[s[i]] != 0)
                mp[s[i]] += 1;
            else
                mp[s[i]] = 1;
        }
        for (auto &it : mp)
        {
            if (it.second == 1)
            {
                if (mp_index[it.first] < smallestIndex)
                    smallestIndex = mp_index[it.first];
            }
        }
        if (smallestIndex == s.size())
            smallestIndex = -1;
        return smallestIndex;
    }

    int firstUniqChar(string s)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] == 1)
                return i;
        }
        return -1;
    }
};

int main()
{
    string input = "loveleetcode";
    Solution s;
    printf("first unique index: %d\n", s.firstUniqChar(input));
}