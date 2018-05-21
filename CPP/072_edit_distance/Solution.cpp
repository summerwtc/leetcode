/**
Website: https://leetcode.com/problems/edit-distance/description/

72. Edit Distance
DescriptionHintsSubmissionsDiscussSolution
Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

You have the following 3 operations permitted on a word:

Insert a character
Delete a character
Replace a character
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u') 

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1Size = word1.size();
        int word2Size = word2.size();

        //distanceMatrix[word1Size + 1][word2Size + 1] = {0}
        vector<vector<int>>distanceMatrix(word1Size + 1, vector<int>(word2Size + 1, 0)); 

        for (int row = 0; row <= word1Size; ++row) {
            distanceMatrix[row][0] = row;
        }

        for (int column = 0; column <= word2Size; ++column) {
            distanceMatrix[0][column] = column;
        }

        for (int i = 1; i <= word1Size; ++i) {
            for (int j = 1; j <= word2Size; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    distanceMatrix[i][j] = distanceMatrix[i - 1][j - 1];
                }
                else {
                    //min(distanceMatrix[i - 1][j - 1], distanceMatrix[i - 1][j], distanceMatrix[i][j - 1]) + 1
                    distanceMatrix[i][j] = min(distanceMatrix[i - 1][j - 1], min(distanceMatrix[i - 1][j], distanceMatrix[i][j - 1])) + 1;
                }
            }
        }
        return distanceMatrix[word1Size][word2Size];
    }
};

class Test {
public:
    void testSolution() {
        test_minDistance("horse", "ros");

        test_minDistance("intention", "execution");

        test_minDistance("", "test");
    }

private:
    void test_minDistance(string word1, string word2) {
        Solution solution;
        int result = solution.minDistance(word1, word2);
        cout << "Input : string 1 = " << word1 << endl;
        cout << "Input : string 2 = " << word2 << endl;
        cout << "Output: " << result << endl;
        cout << endl;
    }
};

int main() {
    Test test;
    test.testSolution();
    return 0;
}
