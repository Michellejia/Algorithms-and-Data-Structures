#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // Here parameter needs to use reference or pointer, otherwise parameter
    // will make a copy of the argument and the argument vector will not actually be changed.
    void quickSort(vector<int> &origin, int left, int right)
    {

        if (left >= right)
            return;

        int base = origin[left];
        int i = left;
        int j = right;

        while (i < j)
        {
            while (origin[j] >= base && i < j)
                j--;
            if (i < j)
                origin[i] = origin[j];
            while (origin[i] <= base && i < j)
                i++;
            if (i < j)
                origin[j] = origin[i];
        }
        origin[i] = base;

        quickSort(origin, left, i - 1);
        quickSort(origin, i + 1, right);
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double res = 0;

        vector<int> merged;
        for (auto i = nums1.begin(); i < nums1.end(); i++)
        {
            merged.push_back(*i);
        }

        for (auto j = nums2.begin(); j < nums2.end(); j++)
        {
            merged.push_back(*j);
        }

        quickSort(merged, 0, merged.size() - 1);

        int size = merged.size();
        if (size % 2 == 0)
        {
            double first = merged[size / 2 - 1];
            double second = merged[size / 2];
            res = (first + second) / 2.0;
        }
        else
        {
            res = merged[size / 2];
        }
        return res;
    }
};

int main()
{
    vector<int> a = {1, 2};
    vector<int> b = {1, 1};
    Solution s;
    double res = s.findMedianSortedArrays(a, b);
    std::cout << res << endl;
}