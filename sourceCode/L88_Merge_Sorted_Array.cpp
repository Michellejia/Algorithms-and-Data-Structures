#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    // the thought is completely wrong, bcs after swapping,
    // the swapped element in nums2 may be bigger than its succeeding elements
    vector<int> merge_(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = 0, j = 0;
        if (n > 0 && nums2[n - 1] < nums1[0])
        {
            for (int k = m; k < nums1.size(); k++)
                nums1[k] = nums1[k - n];
            for (int l = 0; l < m; l++)
                nums1[l] = nums2[l];
        }
        else
        {
            while (i < m && j < n)
            {
                while (i < m && nums1[i] <= nums2[j])
                    i++;
                if (nums1[i] == 0)
                    break;
                swap(nums1[i], nums2[j]);
            }
            while (i < nums1.size() && j < n)
                nums1[i++] = nums2[j++];
        }

        return nums1;
    }

    vector<int> merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> sorted(m + n);
        int i = 0;
        int j = 0;
        while (i < m || j < n)
        {
            if (i == m)
                for (; j < n; j++)
                    sorted[i + j] = nums2[j];
            else if (j == n || n == 0)
                for (; i < m; i++)
                    sorted[i + j] = nums1[i];
            else if (nums1[i] < nums2[j])
            {
                sorted[i + j] = nums1[i];
                i++;
            }
            else
            {
                sorted[i + j] = nums2[j];
                j++;
            }
        }
        nums1 = sorted;
        // for (int i = 0; i < m + n; i++)
        //     nums1[i] = sorted[i];
        return nums1;
    }
};

int main()
{
    vector<int> nums1 = {1,0};
    vector<int> nums2 = {2};
    int num1 = 1;
    int num2 = 1;
    Solution s;
    vector<int> res = s.merge(nums1, num1, nums2, num2);
    for (int i = 0; i < nums1.size(); i++)
    {
        printf("%d\n", res[i]);
    }
}