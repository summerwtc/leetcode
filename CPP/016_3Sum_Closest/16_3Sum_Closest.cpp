/*
Websit :  https://leetcode.com/problems/3sum-closest/description/


Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).


*/

// Method 1:

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int answer = nums[0] + nums[1] + nums[2];
        int size = nums.size();
        int twoSum = 0;
        
        //sort this vector
        std::sort(nums.begin(), nums.end());

        for (int index = 0; index < size - 2; ++index) {
            twoSum = twoSumClosest(nums, index + 1, size - 1, target - nums[index]);
            if (abs(answer - target) > abs(twoSum + nums[index] - target)) {
                answer = twoSum + nums[index];
            }
        }

        return answer;
    }
    
    //get the sum of two integers which is most close two the target.
    int twoSumClosest(vector<int> &nums, int begin, int end, int target) {
        int result = nums[begin] + nums[end];

        while (begin < end) {
            int twoSum = nums[begin] + nums[end];

            //update result
            if (abs(twoSum - target) < abs(result - target)) {
                result = twoSum; 
            }

            if (twoSum == target) {
                return result;
            } else if (twoSum < target) {
                ++begin;
            } else {
                --end;
            }
        }
        return result;
    }
};



// Method 2

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        //sort nums from lowest to highest
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        int answer = nums[0] + nums[1] + nums[2];

        for (int index = 0; index < size - 2; ++index) {
            int start = index + 1;
            int end = size - 1;

            while (start < end) {
                int threeSum = nums[index] + nums[start] + nums[end];
                if (abs(threeSum - target) < abs(answer - target)) {
                    answer = threeSum;
                }
                if ( threeSum < target) {
                    ++start;
                }  else if (threeSum > target) {
                    --end;
                } else {
                    // threeSum is equal to target
                    return target;
                }
            }
        }
        return answer;
    }
};
