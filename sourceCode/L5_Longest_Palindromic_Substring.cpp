#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s, int first, int last)
    {
        int i = first, j = last;
        while (i < j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    //Brute-Force
    string longestPalindrome_v1(string s)
    {
        int stringSize = s.size();
        int first = 0;
        int longestLength = 0;
        int length = 0;
        string longestPalindrome = s;
        while (first <= stringSize)
        {
            int last = stringSize - 1;
            while (first <= last)
            {
                if (isPalindrome(s, first, last))
                {
                    length = last - first + 1;
                    if (length > longestLength)
                    {
                        longestPalindrome = s.substr(first, length);
                        longestLength = length;
                    }
                }
                last--;
            }
            first++;
        }
        return longestPalindrome;
    }

    //Dynamic Programming
    string longestPalindrome_v2(string s)
    {
        int stringLength = s.size();
        int begin = 0;
        int longest = 0;
        int longestFirst = 0, longestLast = 0;
        // create a 2D array
        // dp[i][j] represents string from index i to j
        vector<vector<int>> dp(stringLength, vector<int>(stringLength));
        // strings with length 1 are always palindrome
        for (int i = 0; i < stringLength; i++)
        {
            dp[i][i] = true;
        }

        // Palindrome length range from 3
        for (int L = 2; L <= stringLength; L++)
        {
            for (int i = 0; i < stringLength; i++)
            {
                int j = i + L - 1;
                if (j > stringLength - 1)
                    break;
                if (s[i] == s[j])
                {
                    if (L == 2)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }

        for (int i = 0; i < stringLength; i++)
        {
            for (int j = 0; j < stringLength; j++)
            {
                if (dp[i][j] == true && j - i + 1 > longest)
                {
                    longestFirst = i;
                    longestLast = j;
                    longest = j - i + 1;
                }
            }
        }
        return s.substr(longestFirst, longest);
    }

    //Dynamic Programming
    string longestPalindrome_v3(string s)
    {
        int stringLength = s.size();
        int begin = 0;
        int longest = 1;
        int longestFirst = 0, longestLast = 0;
        // create a 2D array
        // dp[i][j] represents string from index i to j
        vector<vector<int>> dp(stringLength, vector<int>(stringLength));
        // strings with length 1 are always palindrome
        for (int i = 0; i < stringLength; i++)
        {
            dp[i][i] = true;
        }

        // Palindrome length range from 3
        for (int L = 2; L <= stringLength; L++)
        {
            for (int i = 0; i < stringLength; i++)
            {
                int j = i + L - 1;
                if (j > stringLength - 1)
                    break;
                if (s[i] == s[j])
                {
                    if (L == 2)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }

                if(dp[i][j] && j - i + 1 > longest){
                    longestFirst = i;
                    longest = j - i + 1;
                }
                    
            }
        }
        return s.substr(longestFirst, longest);
    }
};

int main()
{
    Solution s;
    string palidroneString;
    string original_string = "babad";
    palidroneString = s.longestPalindrome_v3(original_string);
    //Because %s means a char*, not a std::string.
    //1) Use s.c_str(): use c_str to get the c-string equivalent to the string content
    //2) Use iostreams:
    printf("palindrome: %s\n", palidroneString.c_str());
}