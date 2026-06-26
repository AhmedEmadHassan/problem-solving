#include "bits/stdc++.h"

using namespace std;

class Solution
{
private:
    struct substring
    {
        int startIndex;
        int endIndex;
        int length;
    };
    string str;
    int strSize;
    substring getOddpalindromic(int index)
    {

        substring result = {0, 0, 0};
        int i = index;
        int j = index;
        int length = 1;
        if (i <= 0 || i >= (strSize - 1))
        {
            if (i == 0 || i == strSize - 1)
            {
                return {i, i, 1};
            }
            else
            {
                return result;
            }
        }
        else
        {
            i--;
            j++;
        }
        while (i >= 0 && j < strSize)
        {
            if (str[i] != str[j])
            {
                break;
            }
            length += 2;
            i--;
            j++;
        }
        i++;
        j--;
        result.startIndex = i;
        result.endIndex = j;
        result.length = length;
        return result;
    }
    substring getEvenpalindromic(int index)
    {
        substring result = {0, 0, 0};
        int i = index;
        int j = index + 1;
        int length = 2;
        if (index < 0 || index >= strSize - 1)
        {
            return result;
        }
        else if (str[i] != str[j])
        {
            return {i, i, 0};
        }
        else
        {
            i--;
            j++;
        }
        while (i >= 0 && j < strSize)
        {
            if (str[i] != str[j])
            {
                break;
            }
            length += 2;
            i--;
            j++;
        }
        i++;
        j--;
        result.startIndex = i;
        result.endIndex = j;
        result.length = length;
        return result;
    }

public:
    string longestPalindrome(string s)
    {
        str = s;
        strSize = s.size();
        string result = "";
        substring bestSubstring = {0, 0, 0};
        substring currentSubstring = {0, 0, 0};
        for (int i = 0; i < strSize; i++)
        {
            currentSubstring = getOddpalindromic(i);
            bestSubstring = currentSubstring.length > bestSubstring.length ? currentSubstring : bestSubstring;
        }
        for (int i = 0; i < strSize; i++)
        {
            currentSubstring = getEvenpalindromic(i);
            bestSubstring = currentSubstring.length > bestSubstring.length ? currentSubstring : bestSubstring;
        }
        return s.substr(bestSubstring.startIndex, bestSubstring.length);
    }
};

int main()
{
    Solution solution;
    string s = "babad";
    string result = solution.longestPalindrome(s);
    cout << "The Output is : " << result;
    return 0;
}