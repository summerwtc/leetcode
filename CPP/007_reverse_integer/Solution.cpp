/**
Website: https://leetcode.com/problems/reverse-integer/description/

7. Reverse Integer

Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

*/


#include <iostream>

using namespace std;


class Solution {
public:
    int reverse(int x) {
        int flag = x < 0 ? -1 : 1;

        int64_t num = x;
        if (num < 0) {
            num = -num;
        }

        int64_t answer = 0;
        while (num) {
            int remainder = num % 10;
            answer = answer * 10 + remainder;
            num /= 10;
        }
        if ((answer < INT_MIN) || (answer > INT_MAX)) {
            return 0;
        }
        else {
            return (int)(answer * flag);
        }
    }
};


class Test {
public:
    void testSolution() {
        int x = 123;
        test_resvers(x);
        cout << endl;

        x = -230;
        test_resvers(x);

        //x = -2147483648;
        //test_resvers(x);
    }
private:
    void test_resvers(int x) {
        Solution solution;
        int result = solution.reverse(x);
        cout << "Before reverse : " << x << endl;
        cout << "After reverse : " << result << endl;
    }
};

int main() {
    Test test;
    test.testSolution();
    return 0;
}
