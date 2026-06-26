#include <iostream>
#include "bits/stdc++.h"
#include <math.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int result = 0;
        int i = 0;
        int j = 0;
        unordered_set<int> mySet;
        int stringSize = s.size();
        while (j < stringSize && i < stringSize)
        {
            // if j item don't exist in set
            if (mySet.count(s[j]) == 0)
            {
                // Increment j and put it in set
                mySet.insert(s[j]);
                j++;
            }
            else // if item exist in the set
            {
                // set the new max count
                int setSize = mySet.size();
                result = setSize > result ? setSize : result;
                // Decrement i and remove i element from the set
                mySet.erase(s[i]);
                i++;
            }
            if (j >= stringSize)
            {
                int setSize = mySet.size();
                result = setSize > result ? setSize : result;
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    string str = "a";
    int result = solution.lengthOfLongestSubstring(str);
    cout << "Solution is: " << result << endl;
    return 0;
}