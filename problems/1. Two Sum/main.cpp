#include <iostream>
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    // vector<int> twoSum(vector<int>& nums, int target) {
    //     vector<int> result = {};
    //     for(int i=0;i< (int)nums.size()-1;i++)
    //     {
    //         for(int j=i+1;j<(int)nums.size();j++)
    //         {
    //             if(nums[i] + nums[j] == target)
    //             {
    //                 return {i,j};
    //             }
    //         }   
    //     }
    //     return result;
    // }
    struct Pair
    {
        int value;
        int index;
    };
    vector<Pair> MapToPair(vector<int>& nums)
    {
        vector<Pair> result;
        for(int i=0;i<nums.size();i++)
        {
            result.push_back(Pair{nums[i],i});
        }
        return result;
    }
    vector<Pair> MapToSortedPair(vector<int>& nums)
    {
        vector<Pair> result = MapToPair(nums);
        sort(result.begin(),result.end(),[](const Pair& a, const Pair& b){return a.value < b.value;});
        return result;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<Pair> numbersPair = MapToSortedPair(nums);
        int leftIndex =0, rightIndex = numbersPair.size() -1;
        vector<int> result = {};
        while(leftIndex < rightIndex)
        {
            int sum = numbersPair[leftIndex].value + numbersPair[rightIndex].value;
            if (sum == target) break;
            if(sum < target)
            {
                leftIndex++;
            }
            else
            {
                rightIndex--;
            }
            
        }

        return {numbersPair[leftIndex].index,numbersPair[rightIndex].index};
    }
};
void print(vector<int> vec)
{
    int i = 0;
    int vectorsize = vec.size() -1;
    for(auto var : vec)
    {
        if(i == 0)
        {
            std::cout << "{ ";
        }
        std::cout << var ;
        if(i < vectorsize)
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
    Solution solution = Solution();
    vector<int> nums = {2,7,11,15}; 
    int target = 9;
    vector<int> result = solution.twoSum(nums,target);
    print(result);
    return 0;
}