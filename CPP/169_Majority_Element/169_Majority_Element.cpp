/**
WebSite: https://leetcode.com/problems/majority-element/

    169. Majority Element

    Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.

    You may assume that the array is non-empty and the majority element always exist in the array.
*/


//Method 1
//Time Complexity O(n)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        int maxCount = 0;
        int answer = nums[0];
    
        for (int start = 0; start < size; ) {
            int end = start + 1;
            while(end < size) {
                if(nums[end] == nums[start]) {
                    ++end;
                } else {
                    break;
                }
            }
            if (maxCount < (end - start)) {
                maxCount = end - start;
                answer = nums[start];
            }
            //update start;
            start = end;
        }
        return answer;
    }
};

//Method 2
//Time Complexity: O(n)
/* 
* Moore Vote method: delete the two value if they are not equal,
* the last value is the answer 
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int answer = 0;
    
        for (int i = 0; i < nums.size(); ++i) {
            if (0 == count) {
                answer = nums[i];
                ++count;
            } else {
                if (answer == nums[i]) {
                    ++count;
                } else {
                    --count;
                }
            }
        }
        return answer;
    }
};
