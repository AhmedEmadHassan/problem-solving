#include "bits/stdc++.h"

using namespace std;

#define IS_EVEN(n) (n % 2 == 0)
#define IS_ODD(n) (n % 2 == 1)
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        double result = 0.0;
        multiset<int> set;

        for (int num : nums1)
        {
            set.insert(num);
        }
        for (int num : nums2)
        {
            set.insert(num);
        }
        auto previousI = set.begin();
        auto i = set.begin();
        auto j = set.end();
        j--;
        while (j != i && j != previousI)
        {
            previousI = i;
            i++;
            j--;
        }
        if (j == i)
        {
            result = *j;
        }
        else
        {
            result = (*i + *j) / 2.0;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums1 = {-5};
    vector<int> nums2 = {5};
    double result = solution.findMedianSortedArrays(nums1, nums2);
    cout << "The Output is : " << result;
    return 0;
}