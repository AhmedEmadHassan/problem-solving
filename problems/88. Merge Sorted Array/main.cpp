#include "bits/stdc++.h"

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> result(m + n);
        int i = 0, j = 0;
        int index = 0;
        while (index < m + n)
        {
            if (i < m && j < n)
            {
                if (nums1[i] < nums2[j])
                {
                    result[index] = nums1[i];
                    i++;
                }
                else
                {
                    result[index] = nums2[j];
                    j++;
                }
            }
            else if (i < m)
            {
                result[index] = nums1[i];
                i++;
            }
            else if (j < n)
            {
                result[index] = nums2[j];
                j++;
            }
            index++;
        }
        for (int i = 0; i < (m + n); i++)
        {
            nums1[i] = result[i];
        }
    }
};

void print(vector<int> vec);

int main()
{
    Solution solution;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    solution.merge(nums1, nums1.size() - nums2.size(), nums2, nums2.size());
    print(nums1);
    return 0;
}

void print(vector<int> vec)
{
    int i = 0;
    int vectorsize = vec.size() - 1;
    for (auto var : vec)
    {
        if (i == 0)
        {
            std::cout << "{ ";
        }
        std::cout << var;
        if (i < vectorsize)
        {
            std::cout << ", ";
        }
        else
        {
            std::cout << " }";
            std::cout << std::endl;
        }
        i++;
    }
    std::cout << std::endl;
}
