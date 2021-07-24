#include <math.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

#define INTMAX 2147483647
#define INTMIN -2147483648

class Solution
{
public:
    // Brute-Force (not good)
    int myAtoi_v1(string s)
    {
        int res = 0;
        int prev = 0;
        bool negative = false;
        int j = 0;
        while (s[j] == ' ')
            j++;

        if (s[j] == '-')
            negative = true;

        if (s[j] == '+' || s[j] == '-')
            j++;

        for (int i = j; i < s.size(); i++)
        {

            // if (res == 0 && (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z'))
            //     return res; -> break

            if (s[i] < '0' || s[i] > '9')
                break;

            if (s[i] >= '0' && s[i] <= '9')
            {
                // A good way to prove overflow is to directly divide by 10 to see the previous value.(x)
                // Will have overflow 32-bit error, default the environment does not allow to store 64-bit integers
                // use the method in L7.cpp
                // if (res / 10 != prev)
                // {
                //     if (negative)
                //         res = -pow(2, 31);
                //     else
                //         res = pow(2, 31) - 1;
                //     return res;
                // }

                // prev = res;
                if (res > INTMAX / 10 || res == INTMAX / 10 && s[i] - '0' > 7)
                {
                    if (negative)
                        res = INTMIN;
                    else
                        res = INTMAX;
                    return res;
                }
                else
                    // need to add () otherwise res * 10 + s[i] may overflow first
                    res = res * 10 + (s[i] - '0');
            }
        }

        return negative ? -res : res;
    }

    // Deterministic Finite Automaton(DFA)
    int myAtoi_v2(string s){

    }

    //python 正则表达式？
};

int main()
{
    Solution s;
    printf("converted is %d\n", s.myAtoi_v1("00000-42a1234"));
}