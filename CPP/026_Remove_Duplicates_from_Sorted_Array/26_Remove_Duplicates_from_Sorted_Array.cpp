/*
Website : https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/ 

26. Remove Duplicates from Sorted Array

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //nums is a sorted vector 
        int size = nums.size();
        if (size < 2) {
            return size;
        }

        int begin = 0;
        int next = begin + 1;

        while (next < size) {
            while ((next < size) && (nums[next - 1 ] == nums[next])) {
                ++next;
            }
            if (next < size) {
                nums[++begin] = nums[next++];
            }
        }
        return (begin + 1);
    }
};
