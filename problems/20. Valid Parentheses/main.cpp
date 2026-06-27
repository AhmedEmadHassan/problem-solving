#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> charStack;
        unordered_map<char, char> myMap = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'},
            {')', '('},
            {'}', '{'},
            {']', '['},
        };
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                charStack.push(s[i]);
            }
            else
            {
                if (!charStack.empty())
                {
                    if (charStack.top() == myMap[s[i]])
                    {
                        charStack.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (charStack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution solution;
    string s = "(){}";
    bool result = solution.isValid(s);
    cout << result;
    return 0;
}