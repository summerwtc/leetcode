/**
Website : https://leetcode.com/problems/string-to-integer-atoi/description/

8. String to Integer (atoi)

    Implement atoi which converts a string to an integer.
    
    The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
    
    The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
    
    If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
    
    If no valid conversion could be performed, a zero value is returned.
    
    Note:
    
    Only the space character ' ' is considered as whitespace character.
    Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
    Example 1:
    
    Input: "42"
    Output: 42
    Example 2:
    
    Input: "   -42"
    Output: -42
    Explanation: The first non-whitespace character is '-', which is the minus sign.
                Then take as many numerical digits as possible, which gets 42.
             Example 3:
    
             Input: "4193 with words"
             Output: 4193
             Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
             Example 4:
    
             Input: "words and 987"
             Output: 0
             Explanation: The first non-whitespace character is 'w', which is not a numerical 
                          digit or a +/- sign. Therefore no valid conversion could be performed.
                  Example 5:
    
                  Input: "-91283472332"
                  Output: -2147483648
                  Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
                               Thefore INT_MIN (−231) is returned.
    
*/


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        string formatStr = formatString(str);
        if (formatStr.empty()) {
            return 0;
        }
        int size = formatStr.size();
        
        bool isNegative = false;
        int index = 0;

        if (formatStr[index] == '-') {
            isNegative = true;
            index++;
        }
        else if (formatStr[index] == '+') {
            isNegative = false;
            index++;
        }

        int64_t answer = 0;
        for (; index < size; ++index) {
            answer = answer * 10 + (formatStr[index] - '0');
            if (answer > INT_MAX) {
                break;
            }
        }

        if (isNegative) {
            answer *= -1;
        }
        if (answer > INT_MAX) {
            return INT_MAX;
        }
        if (answer < INT_MIN) {
            return INT_MIN;
        }
        return answer;
    }

private:
    //format string
    string formatString(string str) {
        //discards whitespace characters
        size_t firstFound = str.find_first_not_of(" "); 
        if (firstFound == string::npos) {
            return "";
        }

        size_t firstDigit = firstFound;
        if ((str[firstFound] == '-') || (str[firstFound] == '+')) {
            firstDigit = firstFound + 1;
            if ((firstDigit >= str.size()) ||(str[firstDigit] < '0') || (str[firstDigit] > '9')) {
                return "";
            }
        }
        else {
            if ((str[firstDigit] < '0') || (str[firstDigit] > '9')) {
                return "";
            }
        }

        //find the last digit character
        size_t lastDigit = str.find_first_not_of("0123456789", firstDigit);
        if (lastDigit == string::npos) {
            lastDigit = str.size() - 1;
        }
        else {
            lastDigit -= 1;
        }

        return  str.substr(firstFound, lastDigit - firstFound + 1);
    }

};

class Test {
public:
    void testSolution() {
        test_myAtoi("  ");
        cout << endl;
        
        test_myAtoi("only words");
        cout << endl;

        test_myAtoi(" +123");
        cout << endl;

        test_myAtoi(" -456");
        cout << endl;

        test_myAtoi("words and 987");
        cout << endl;

        test_myAtoi("-91283472332"); // expect -2147483648
        cout << endl;

        test_myAtoi("9223372036854775808");
        cout << endl;

        test_myAtoi(" +123.456 with dot");
    }
private:
    void test_myAtoi(string str) {
        Solution solution;
        int num = solution.myAtoi(str);
        cout << "Input : " << str << endl;
        cout << "Output : " << num << endl;
    }
};

int main() {
    Test test;
    test.testSolution();
    return 0;
}
