/*
WebSite: https://leetcode.com/problems/contains-duplicate/

    217. Contains Duplicate

    Given an array of integers, find if the array contains any duplicates.
    Your function should return true if any value appears at least twice in the array,
    and it should return false if every element is distinct. 
*/

//Method 1
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
    
        for (int i = 0; i < size - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};

//Method 2
//using map
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> myset;
        std::set<int>::iterator it;
    
        for (int i = 0; i < nums.size(); ++i) {
            if (myset.find(nums[i]) == myset.end()) {
                myset.insert(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
