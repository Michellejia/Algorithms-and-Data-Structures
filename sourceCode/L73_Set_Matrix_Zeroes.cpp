#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int h = matrix.size();
        int w = matrix[0].size();
        vector<int> tmp(h + w, 0);
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (matrix[i][j] == 0)
                {
                    tmp[i] = 1;
                    tmp[h + j] = 1;
                }
            }
        }

        // not good
        for (int k = 0; k < h + w; k++)
        {
            if (tmp[k] == 1)
            {
                if (k < h)
                {
                    for (int p = 0; p < w; p++)
                        matrix[k][p] = 0;
                }
                else
                {
                    for (int q = 0; q < h; q++)
                        matrix[q][k - h] = 0;
                }
            }
        }
        // better
        // for (int i = 1; i < h; i++)
        // {
        //     for (int j = 1; j < w; j++)
        //     {
        //         if (!matrix[i][0] || !matrix[0][j])
        //         {
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    Solution s;
    s.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}