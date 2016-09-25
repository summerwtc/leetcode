/**
WebSite: https://leetcode.com/problems/rotate-array/

    189. Rotate Array

    Rotate an array of n elements to the right by k steps.

    For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

    Note:
    Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem. 
*/

//Method 1
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (0 >= k) {
            return;
        }
        int size = nums.size();
        k = k % size;
    
        vector<int>::iterator it = nums.begin();
        vector<int>tempVec(nums.begin() + size - k, nums.end());
        int j = size -1;
        for (int i = size - k -1; i >= 0; --i) {
            nums[j--] = nums[i];
        }
        for (int i = 0; i < tempVec.size(); ++i) {
            nums[i] = tempVec[i];
        } 
    }
};

//Method 2
/*
* For Example:
* arr = 1 2 3 4 5 6 7, k = 3
* first:  8 7 6 5 4 3 2 1,
* second: 6 7 8 5 4 3 2 1
* third:  6 7 8 1 2 3 4 5
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0) {
            return;
        }
        k %= nums.size();
        std::reverse(nums.begin(), nums.end());
        std::reverse(nums.begin(), nums.begin() + k);
        std::reverse(nums.begin() + k, nums.end());
    }
};
