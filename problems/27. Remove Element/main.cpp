#include "bits/stdc++.h"

using namespace std;

class Solution
{
    void swap(vector<int> &nums, int index1, int index2)
    {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }

public:
    int removeElement(vector<int> &nums, int val)
    {
        set<int> set;
        int counter = 0;
        int numsSize = nums.size();
        for (int i = 0; i < numsSize; i++)
        {
            if (nums[i] == val)
            {
                set.insert(i);
                counter++;
            }
        }

        for (int i = numsSize - 1; i > (numsSize - 1 - counter); i--)
        {
            if (nums[i] != val)
            {
                swap(nums, i, *set.begin());
                set.erase(set.begin());
            }
            else
            {
                set.erase(i);
            }
        }
        return numsSize - counter;
    }
};

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

int main()
{
    Solution Solution;
    vector<int> nums = {3, 2, 2, 3};
    int val = 3;
    int result = Solution.removeElement(nums, val);
    cout << "The Result: " << result << endl;
    print(nums);
    return 0;
}