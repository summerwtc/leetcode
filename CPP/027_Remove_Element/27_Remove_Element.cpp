/*
link :  https://leetcode.com/problems/remove-element/description/

27. Remove Element

Given an array and a value, remove all instances of that value in place and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.

*/

//Method 1

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int begin = 0, next = 0;
        int size = nums.size();

        while (next < size) {
            //find the integer which is not equal to val 
            while ((next < size) && (nums[next] == val)) {
                ++next;
            }
            if (next < size) {
                nums[begin++] = nums[next++];
            } else {
                break;
            }
        }
        return begin;
    }
};


//Method 2 
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int begin = 0, next = 0;

        while (next < nums.size()) {
            if (nums[next] != val) {
                nums[begin++] = nums[next++];
            } else {
                ++next;
            }
        }
        return begin;
    }
};

