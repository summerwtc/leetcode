/**
Website : https://leetcode.com/problems/palindrome-number/description/

9. Palindrome Number

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?

*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int result = reverseInteger(x); 
        if (x == result){
            return true;
        }
        else {
            return false;
        }
    }

private:
    int reverseInteger(int x) {
        int result = 0;

        while (x) {
            result = result * 10 + x % 10;
            x = x / 10;
        }

        return result;
    }
};


class Test {
public:
    void testSolution() {
        test_isPalindrome(101);
        cout << endl;

        test_isPalindrome(-121);
        cout << endl;

        test_isPalindrome(0);
        cout << endl;
    }
private:
    void test_isPalindrome(int x) {
        Solution solution;
        bool isPal = solution.isPalindrome(x);

        if (isPal) {
            cout << "x = " << x << " is Palindrome." << endl;
        }
        else {
            cout << "x = " << x << " is not Palindrome." << endl;
        }
    }
};

int main() {
    Test test;
    test.testSolution();
    return 0;
}
