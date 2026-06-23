#include <iostream>
#include <math.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    int stringCharToNumber(char c)
    {
        return c - '0';
    }
    char numberToStringChar(int num)
    {
        return num + '0';
    }
    int GetDigitValue(int number, int numberIndex)
    {
        return (number % (int)pow(10, numberIndex + 1)) / (int)pow(10, numberIndex);
    }
    string convertToNumber(ListNode *list)
    {
        string result;
        ListNode *ListIterator = list;
        while (ListIterator != nullptr)
        {
            result.push_back(numberToStringChar(ListIterator->val));
            ListIterator = ListIterator->next;
        }
        return result;
    }
    ListNode *convertToList(string number)
    {
        ListNode *result = new ListNode();
        ListNode *resultIterator = result;
        bool isFinished = false;
        int index = 0;
        int numberSize = number.size();
        while (!isFinished)
        {
            int digit = stringCharToNumber(numberSize > index ? number[index] : '0');
            if (digit == 0)
            {
                if ((int)number.length() <= index)
                {
                    isFinished = true;
                    break;
                }
            }
            if (index == 0)
            {
                resultIterator->val = digit;
            }
            else
            {
                resultIterator->next = new ListNode(digit);
                resultIterator = resultIterator->next;
            }
            // Increment
            index++;
        }
        return result;
    }
    string AddNumbers(string num1, string num2)
    {
        string result;
        int index = 0;
        int carry = 0;
        int num1Size = num1.size();
        int num2Size = num2.size();
        while (index < num1Size || index < num2Size || carry > 0)
        {
            int number1 = num1Size > index ? stringCharToNumber(num1[index]) : 0;
            int number2 = num2Size > index ? stringCharToNumber(num2[index]) : 0;
            int sum = number1 + number2 + carry;
            if (sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            // Take Action
            result.push_back(numberToStringChar(sum));
            // Increment
            index++;
        }
        return result;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = NULL;
        string num1 = convertToNumber(l1);
        string num2 = convertToNumber(l2);
        string sum = AddNumbers(num1, num2);
        result = convertToList(sum);
        return result;
    }
};

void print(ListNode *list)
{
    ListNode *ListIterator = list;
    int index = 0;
    while (ListIterator != NULL)
    {
        if (index != 0)
        {
            cout << ", ";
        }
        cout << ListIterator->val;
        // Increment
        index++;
        ListIterator = ListIterator->next;
    }
    cout << endl;
}
int main()
{
    Solution solution = Solution();
    // ListNode list1 = ListNode(2, new ListNode(4, new ListNode(3)));
    // ListNode list2 = ListNode(5, new ListNode(6, new ListNode(4)));
    ListNode list1 = ListNode(0);
    ListNode list2 = ListNode(7, new ListNode(3));
    ListNode *result = solution.addTwoNumbers(&list1, &list2);
    cout << "List1: ";
    print(&list1);
    cout << "List2: ";
    print(&list2);
    cout << "Result: ";
    print(result);
    return 0;
}