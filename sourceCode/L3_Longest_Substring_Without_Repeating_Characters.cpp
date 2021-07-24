#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    // subsequence
    // int lengthOfLongestSubstring(string s)
    // {
    //     int longestLength = 0;
    //     // Spaces belong to char
    //     unordered_map<char, int> mp;

    //     for (int i = 0; i <= s.size(); i++)
    //     {
    //         if (mp.count(s[i]) > 0 || i == s.size())
    //         {
    //             if (longestLength < mp.size())
    //                 longestLength = mp.size();
    //             mp.erase(mp[s[i]]);
    //         }
    //         mp[s[i]] = i + 1;
    //     }
    //     return longestLength;
    // }

    int lengthOfLongestSubstring(string s)
    {
        int longestLength = 0;
        unordered_map<char, int> mp;
        int begin = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (mp.count(s[i]) > 0)
                // The sliding window `begin` is impossible to go back
                begin = max(mp[s[i]] + 1, begin);
            mp[s[i]] = i;
            longestLength = max(i - begin + 1, longestLength);
        }
        return longestLength;
    }
};

int main()
{
    Solution s;
    int res = s.lengthOfLongestSubstring("dvdf");
    std::cout << res << endl;
    return 0;
}
