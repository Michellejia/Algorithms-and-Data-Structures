#include <vector>
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        vector<int> numbers;
        int reversedNumber;
        // if (x > pow(2, 31) - 1 || x < -pow(2, 31))
        //     return 0;

        while (x % 10 || x / 10)
        {
            numbers.push_back(x % 10);
            x = x / 10;
        }

        for (int i = 0; i < numbers.size(); i++)
        {
            // This judgment is wrong, because the environment does not allow you to store 64-bit integers is assumed in the title, 
            // but in fact 64-bit exists in the system, so it needs to be judged by the last two digits in advance.
            if (reversedNumber + numbers[i] * pow(10, numbers.size() - i - 1) > pow(2, 31) - 1 || reversedNumber + numbers[i] * pow(10, numbers.size() - i - 1) < -pow(2, 31))
                return 0;
            reversedNumber += numbers[i] * pow(10, numbers.size() - i - 1);
        }
        return reversedNumber;
    }

    int reverse_v2(int x)
    {
        vector<int> numbers;
        int reversedNumber = 0;

        while (x % 10 || x / 10)
        {
            // Start to judge with the last two digits in advance
            int tmp2_0 = pow(2, 31) - 1;
            int tmp1 = tmp2_0 / 10;
            int tmp2 = tmp2_0 % 10;

            int tmp4_0 = -pow(2, 31);
            int tmp3 = tmp4_0 / 10;
            int tmp4 = tmp4_0 % 10;
            if (reversedNumber > tmp1 || reversedNumber == tmp1 && x % 10 > tmp2 || reversedNumber < tmp3 || reversedNumber == tmp3 && x % 10 < tmp4)
                return 0;
            reversedNumber = reversedNumber * 10 + x % 10;
            x = x / 10;
        }

        return reversedNumber;
    }
};

int main()
{
    int x = 1534236469;
    Solution s;
    printf("reversed number is: %d\n", s.reverse_v2(x));
}