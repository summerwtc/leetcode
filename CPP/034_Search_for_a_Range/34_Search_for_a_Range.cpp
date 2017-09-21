/*
Link :  https://leetcode.com/problems/search-for-a-range/description/

34. Search for a Range

Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //nums is sorted in ascending order
        vector<int> answer;
        int size = nums.size();

        int begin = 0;
        int end = size - 1;
        int middle = 0;

        while (begin <= end) {
            middle = (begin + end) / 2;
            if (nums[middle] > target) {
                end = middle - 1;
            } else if (nums[middle] < target) {
                begin = middle + 1;
            } else {
                begin = middle - 1;
                end = middle + 1;
                //find the first value which is equal to target
                while ((begin >= 0) && (nums[begin] == target)) {
                    --begin;
                }
                answer.push_back(++begin);

                //find the last value which is equal to targe
                while ((end < size) && (nums[end] == target)) {
                    ++end;
                }	
                answer.push_back(--end);
                return answer;
            }
        }

        //no value  which is equal to target
        if(begin > end) {
            answer.push_back(-1);
            answer.push_back(-1);
            return answer;
        }
    }
};
