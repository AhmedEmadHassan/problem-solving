#include "bits/stdc++.h"
using namespace std;

#define IS_ALPHABETIC(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
#define IS_ALPHANUMERIC(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
#define TO_LOWER(c) (((c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c))
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0;
        int j = s.size() - 1;
        bool isSuccess = true;
        int strSize = (int)s.size();
        while (i <= j && (i >= 0 && i < strSize - 1) && (j >= 1 && j < strSize))
        {
            while (!IS_ALPHANUMERIC(s[i]) && ((i >= 0 && i < strSize - 1)))
                i++;
            while (!IS_ALPHANUMERIC(s[j]) && (j >= 1 && j < strSize))
                j--;
            if (TO_LOWER(s[i]) != TO_LOWER(s[j]))
            {
                if (!IS_ALPHANUMERIC(s[i]) && !IS_ALPHANUMERIC(s[j]))
                {
                    break;
                }
                isSuccess = false;
            }
            i++;
            j--;
        }
        return isSuccess;
    }
};

int main()
{
    Solution solution;
    string str = ".,";
    bool result = solution.isPalindrome(str);
    cout << "The Result is: " << result;
    return 0;
}