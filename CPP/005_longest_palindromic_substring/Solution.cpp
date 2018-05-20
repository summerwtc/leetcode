/**
Website : https://leetcode.com/problems/longest-palindromic-substring/description/


5. Longest Palindromic Substring

Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"

*/


#include <iostream>
#include <string>

using namespace std;

//Time 0(n*n)
class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        string answer;

        for (int index = 0; index < size; ++index) {
            //if the len of palidrome substring is  odd
            string tmp1 = getPalindrome(s, index, index);

            //if the len of palidrome substring is even
            string tmp2 = getPalindrome(s, index, index + 1);

            if (tmp1.size() > tmp2.size()) {
                if (answer.size() < tmp1.size()) {
                    answer = tmp1;
                }
            }
            else {
                if (answer.size() < tmp2.size()) {
                    answer = tmp2;
                }
            }
        }
        return answer;
    }

private:
    string getPalindrome(string s, int left, int right) {
        if (left > right) {
            return "";
        }

        while ((left >= 0) && (right < (int)s.size())) {
            if (s[left] == s[right]) {
                left--;
                right++;
            }
            else {
                break;
            }
        }

        int len = right - left - 1;
        string answer = s.substr(left + 1, len);

        return answer;
    }
};



//Time O(n * n * n)  : time out
class Solution1 {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        string answer;
        for (int start = 0; start < size; ++start) {
            for (int end = size - 1; end >= start; --end) {
                if (isPalindrome(s, start, end)) {
                    if ((int)answer.size() < (end - start + 1)) {
                        //answer = string(s, start, end - start + 1);
                        answer = s.substr(start, end - start + 1);
                    }
                }
            }
        }
        return answer;
    }
private:
    bool isPalindrome(string str, int start, int end) {
        if (start > end) {
            return false;
        }

        while (start < end) {
            if (str[start] != str[end]) {
                return false;
            }
            else {
                start++;
                end--;
            }
        }
        return true;
    }

};


class Test {
public:
    void testSolution() {
        string str1 = "babad";
        test_longestPalindrome(str1);
        cout << endl;

        string str2 = "cbbd";
        test_longestPalindrome(str2);
        cout << endl;

        string str3 = "a";
        test_longestPalindrome(str3);
        cout << endl;

        string str4(1000, '0'); 
        test_longestPalindrome(str4);
    }
private:
    void test_longestPalindrome(string str) {
        Solution solution;
        string result = solution.longestPalindrome(str);
        cout << "str = " << str << endl;
        cout << "result = " << result << endl;
    }
};

int main() {
    Test test;
    test.testSolution();
    return 0;
}
