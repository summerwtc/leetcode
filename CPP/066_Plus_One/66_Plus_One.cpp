/*
Link : https://leetcode.com/problems/plus-one/description/

66. Plus One

Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.

You may assume the integer do not contain any leading zero, except the number 0 itself.

The digits are stored such that the most significant digit is at the head of the list.
*/


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int index = digits.size() - 1; 
        
        for (; index >= 0; --index) {
            if (digits[index] == 9) {
                digits[index] = 0;
            } else {
                digits[index] += 1;
                return digits;
            }   
        }
        //add 1 at the highest 
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
