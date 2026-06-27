#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int numSize = numbers.size();
        int i = 0, j = numSize - 1;
        int currentValue;
        while (i < j)
        {
            currentValue = numbers[i] + numbers[j];
            if (currentValue > target)
            {
                if (j > 0)
                    j--;
            }
            else if (currentValue < target)
            {
                if (i < numSize - 2)
                    i++;
            }
            else
            {
                return vector<int>{i + 1, j + 1};
            }
        }
        return vector<int>();
    }
};
void print(vector<int> vec);
int main()
{
    Solution solution;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(numbers, target);
    print(result);
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
