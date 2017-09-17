/*
Website: https://leetcode.com/problems/3sum/description/


Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note: The solution set must not contain duplicate triplets.

For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<vector<int>> result;

        //First sort the nums
        sort(nums.begin(), nums.end());
        int end = nums.size() - 1;

        vector<vector<int>>::iterator it;

        for (int start = 0; start < end;  ++start) {
            result = twoSum(nums, start + 1, end, 0 - nums[start]);
            if (result.size() != 0) {
                //insert the nums[start] to the head
                for (int index = 0; index < result.size(); ++index) {
                    result[index].insert(result[index].begin(), nums[start]);
                }

                for (int index = 0; index < result.size(); ++index) {
                    answer.push_back(result[index]);
                }
            }
            while ((start < end) && (nums[start] == nums[start + 1]) )
            {
                ++start;
            } 
        }

        return answer;
    }
    

    //find the two values whose sum is equal to target
    vector<vector<int>> twoSum(vector<int>& nums, int start, int end, int target)
    {
        //Make sure the nums is ascending sorted
        vector<vector<int>> answer;

        while (start < end) {
            if (nums[start] + nums[end] == target) {
                vector<int> result;
                result.push_back(nums[start]);
                result.push_back(nums[end]);
                //save the result
                answer.push_back(result);

                //update start 
                while ((start < end) && (nums[start] == nums[start + 1])) {
                    ++start;
                }
                ++start;

                //update end
                while((end > start) && nums[end] == nums[end - 1]) {
                    --end;
                }
                --end;
            } else if (nums[start] + nums[end] > target) {
                --end;
            } else {
                ++start;
            }
        }
        return answer;
    }
};
