/**
WebSite: https://leetcode.com/problems/move-zeroes/

    283. Move Zeroes


    Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

    For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

    Note:

        You must do this in-place without making a copy of the array.
        Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroStart = 0;
        int size = nums.size();
    
        for (zeroStart = 0; zeroStart < size; ++zeroStart) {
            if (nums[zeroStart] == 0) {
                break;
            }
        }
        if(zeroStart == size) {
            //there is no value that equals to zero 
            return;
        }
    
        for (int i = zeroStart + 1; i < size; ++i) {
            if (nums[i] != 0) {
                nums[zeroStart++] = nums[i];
            }
        }
        if (zeroStart < size) {
            for (int i = zeroStart; i < size; ++i) {
                nums[i] = 0;
            }
        }
    }
};
