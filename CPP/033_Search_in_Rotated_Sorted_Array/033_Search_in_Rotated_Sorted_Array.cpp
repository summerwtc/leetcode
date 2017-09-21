/*
Link : https://leetcode.com/problems/search-in-rotated-sorted-array/description/

33. Search in Rotated Sorted Array

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int answer = -1;

        for (int index = 0; index < nums.size(); ++index) {
            if (nums[index] == target) {
                //reverse part1
                std::reverse(nums.begin(), nums.begin() + index + 1);
                //reverse part2
                std::reverse(nums.begin() + index + 1, nums.end());

                answer = index;
            }
        }

        //reverse the whole vector
        std::reverse(nums.begin(), nums.end());
        return answer;
    }
};
