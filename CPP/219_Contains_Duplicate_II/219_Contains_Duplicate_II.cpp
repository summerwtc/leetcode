/**
Website: https://leetcode.com/problems/contains-duplicate-ii/

    219. Contains Duplicate II

    Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array 
    such that nums[i] = nums[j] and the difference between i and j is at most k. 
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int>myHash;
        std::unordered_map<int, int>::iterator it;
        int size = nums.size();
    
        for (int i = 0 ; i < size; ++i) {
            it = myHash.find(nums[i]);
            if (it != myHash.end()) {
                if (i - it->second <= k) {
                    return true;
                } else {
                    it->second = i;
                }
            } else {
                myHash[nums[i]] = i;
            }
        }
        return false;
    }
};
