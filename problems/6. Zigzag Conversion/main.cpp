#include "bits/stdc++.h"

using namespace std;

class Solution
{
private:
    string str;
    int strSize;
    int numOfRows;
    pair<int, int> getIndexOrder(int n, int ir)
    {
        pair<int, int> result;
        // Equation (2*R-2)*n [±] ir
        if (numOfRows != 1)
        {
            result.first = (2 * numOfRows - 2) * n - ir;
            result.second = (2 * numOfRows - 2) * n + ir;
        }
        else
        {
            result.first = n;
            result.second = n;
        }
        return result;
    }
    vector<int> getRowIndexValues(int ir)
    {
        vector<int> result;
        pair<int, int> currentPair;
        for (int n = 0;; n++)
        {
            currentPair = getIndexOrder(n, ir);

            if (!(currentPair.first >= 0 && currentPair.first < strSize) && !(currentPair.second >= 0 && currentPair.second < strSize))
            {
                break;
            }
            if (currentPair.first == currentPair.second)
            {
                if (currentPair.first >= 0 && currentPair.first < strSize)
                    result.push_back(currentPair.first);
            }
            else if (ir == numOfRows - 1)
            {
                if (currentPair.second >= 0 && currentPair.second < strSize)
                    result.push_back(currentPair.second);
            }
            else
            {
                if (currentPair.first >= 0 && currentPair.first < strSize)
                    result.push_back(currentPair.first);

                if (currentPair.second >= 0 && currentPair.second < strSize)
                    result.push_back(currentPair.second);
            }
        }
        return result;
    }
    vector<int> getAllIndexValues()
    {
        vector<int> result;
        vector<int> currentRowValue;
        for (int ir = 0; ir < numOfRows; ir++)
        {
            currentRowValue = getRowIndexValues(ir);
            result.insert(result.end(), currentRowValue.begin(), currentRowValue.end());
        }
        return result;
    }
    string GetResultString()
    {
        string result;
        vector<int> resultIndexes = getAllIndexValues();
        for (int index : resultIndexes)
        {
            result.push_back(str[index]);
        }
        return result;
    }

public:
    string convert(string s, int numRows)
    {
        // Store Input values
        string result;
        str = s;
        strSize = s.length();
        numOfRows = numRows;
        result = GetResultString();
        return result;
    }
};

int main()
{
    Solution solution;
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string result = solution.convert(s, numRows);
    cout << "The Output is : " << result;
    return 0;
}