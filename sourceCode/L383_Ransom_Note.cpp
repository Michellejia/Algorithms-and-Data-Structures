#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> mp_magazine;
        unordered_map<char, int> mp_ransomNote;
        for (int i = 0; i < magazine.size(); i++)
            mp_magazine[magazine[i]]++;
        for (int j = 0; j < ransomNote.size(); j++)
            mp_ransomNote[ransomNote[j]]++;

        for (auto &it : mp_ransomNote)
        {
            if (mp_magazine.find(it.first) == mp_magazine.end() || \
                mp_ransomNote[it.first] > mp_magazine[it.first])
                return false;
        }
        return true;
    }
};

int main(){
    string magazine = "hjibagacbhadfaefdjaeaebgi";
    string ransomNote = "fihjjjjei";
    Solution s;
    printf("%d\n", s.canConstruct(ransomNote, magazine));
}