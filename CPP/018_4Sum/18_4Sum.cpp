/*
URL : https://leetcode.com/problems/4sum/description/

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note: The solution set must not contain duplicate quadruplets.

For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]

*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        vector<vector<int>> answer;

        for (int index = 0; index < size - 3; ) {
            vector<vector<int>> tmp = threeSum(nums, index + 1, size - 1, target - nums[index]);

            if (0 != tmp.size()) {
                for (auto it : tmp) {
                    it.insert(it.begin(), nums[index]);
                    answer.push_back(it);
                }
            }

            //update index
            while ((index < size - 3) && (nums[index] == nums[index + 1])) {
                ++index;
            }
            ++index;
        }
        return answer;
    }
    
    vector<vector<int>> threeSum(vector<int> &sorted_nums, int low, int high, int target)
    {
        vector<vector<int>> answer;
        //Make sure sorted_nums is sroted from lowest to highest

        for (int index = low; index < high - 1; ) {
            int start = index + 1; 
            int end = high;

            while (start < end) {
                int threeSum = sorted_nums[index] + sorted_nums[start] + sorted_nums[end] ;
                if (threeSum <  target) {
                    ++start;
                } else if (threeSum > target) {
                    --end;
                } else {
                    vector<int> tmpVector;
                    tmpVector.push_back(sorted_nums[index]);
                    tmpVector.push_back(sorted_nums[start]);
                    tmpVector.push_back(sorted_nums[end]);
                    answer.push_back(tmpVector);

                    //update start
                    while((start < end) && (sorted_nums[start] == sorted_nums[start + 1])) {
                        ++start;
                    }
                    ++start;

                    //update end
                    while((start < end) && (sorted_nums[end] == sorted_nums[end - 1])) {
                        --end;
                    }
                    --end;
                }
            }

            //update index
            while((index < high - 1) && (sorted_nums[index] == sorted_nums[index + 1])) {
                ++index;
            }
            ++index;
        }
        return answer;
    }
};
