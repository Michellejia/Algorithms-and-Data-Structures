#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> mp_s;
        unordered_map<char, int> mp_t;
        for (int i = 0; i < s.size(); i++)
            mp_s[s[i]]++;
        for (int j = 0; j < t.size(); j++)
            mp_t[t[j]]++;

        for (auto &it : mp_t)
        {
            if (mp_s.find(it.first) == mp_s.end() ||
                mp_s[it.first] != mp_t[it.first])
                return false;
        }

        for (auto &it : mp_s)
        {
            if (mp_t.find(it.first) == mp_t.end() ||
                mp_t[it.first] != mp_s[it.first])
                return false;
        }
        return true;
    }
};

int main()
{
    string s = "ab";
    string t = "a";
    Solution sol;
    printf("%d\n", sol.isAnagram(s, t));
}