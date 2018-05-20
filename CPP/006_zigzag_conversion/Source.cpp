/**
6. ZigZag Conversion

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I

*/



#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        int size = s.size();
        if (numRows <= 1) {
            return s;
        }

        bool isTop2Buttom = true; //direction is from top to buttom
        vector<string> result(numRows, "");

        for (int index = 0; index < size;) {
            if (isTop2Buttom) {
                for (int row = 0; (row < numRows) && (index < size); ++row) {
                    result[row] += s[index++];
                }
                isTop2Buttom = false;
            }
            else {
                //skip the first and last row
                for (int row = numRows - 2; (row > 0) && (index < size); --row) {
                    result[row] += s[index++];
                }
                isTop2Buttom = true;
            }
        }
        string answer = "";
        for (auto &elment : result) {
            answer += elment;
        }
        return answer;
    }
};

class Test {
public:
    void testSolution() {
        test_convert("abcdefghijklmn", 1);
        cout << endl;

        test_convert("1234567890abcdefghjjklmn", 5);
    }

private:
    void test_convert(string s, int numRows) {
        Solution solution;
        string result = solution.convert(s, numRows);
        cout << "Input :" << s << endl;
        cout << "Output : " << result << endl;
    }
};

int main() {
    Test test;
    test.testSolution();
    return 0;
}
