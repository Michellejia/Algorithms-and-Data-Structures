#include <stdio.h>
#include <iostream>
using namespace std;

class Solution
{
public:
    // Assume smaller # is always located at the right side
    // If left # is smaller than the right #, then there is a substraction
    int romanToInt(string s)
    {
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int pres = getNum(s[i]);
            if (i + 1 < s.size() && getNum(s[i + 1]) > pres)
                res -= pres;
            else
                res += pres;
        }
        return res;
    }

private:
    int getNum(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;

        default:
            return 0;
        }
    }
};

int main(){
    string s = "IV";
    Solution r;
    printf("converted int is: %d\n", r.romanToInt(s));
}