/**
WebSite: https://leetcode.com/problems/pascals-triangle/

    118. Pascal's Triangle

    Given numRows, generate the first numRows of Pascal's triangle.

    For example, given numRows = 5,
    Return

    [
         [1],
        [1,1],
       [1,2,1],
      [1,3,3,1],
     [1,4,6,4,1]
    ]

*/

//Method 1
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer;
        if (numRows <= 0) {
            return answer;
        }
    
        vector<int> vec;
        vec.push_back(1);
        answer.push_back(vec);
    
        for (int i = 1; i < numRows; ++i) {
            vector<int> newVec;
            newVec.push_back(1);
            for (int i = 0; i < vec.size() - 1 ; ++i) {
                newVec.push_back(vec[i] + vec[i + 1]);
            }
            newVec.push_back(1);
            answer.push_back(newVec);
            vec = newVec;
        }
        return answer;
        
    }
};


//method 2
vector<vector<int>> Solution::generate(int numRows)
{
    vector<vector<int>> answer;
    if (numRows <= 0) {
        return answer;
    }

    for(int i = 0; i < numRows; ++i) {
        vector<int> newVec;
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                newVec.push_back(1);
            } else {
                newVec.push_back(answer[i - 1][j -1 ] + answer[i - 1][j]);
            }
        }
        answer.push_back(newVec);
    }
    return answer;
}
