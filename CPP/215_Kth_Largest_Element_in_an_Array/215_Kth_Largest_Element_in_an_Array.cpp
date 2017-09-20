/*
Link : https://leetcode.com/problems/kth-largest-element-in-an-array/description/

215. Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

*/


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       	// 0 <= k < nums.size()
        int size = nums.size();
        return partQuickSort(nums, 0, size - 1, size - k); 
    }
    
    int partQuickSort(vector<int>&nums, int low, int high, int kth) {
        //Make sure : low <= kth <= high
        if (low < high) {
            int middle = myPartition(nums, low, high);
            if (middle > kth) {
                partQuickSort(nums, low, middle - 1, kth);
            } else if (middle < kth) {
                partQuickSort(nums, middle + 1, high, kth);
            } else {
                return nums[kth];
            }
        }
        //now low == high == kth
        return nums[kth];
    }
    
    int myPartition(vector<int>&nums, int low, int high) {
        int val = nums[low];
        while (low < high) {
            while ((low < high) && (val < nums[high])) {
                --high;
            }
            if (low < high) {
                nums[low] = nums[high];
            }

            while ((low < high) && (val >= nums[low])) {
                ++low;
            }
            if (low < high) {
                nums[high] = nums[low];
            }
        }
        //now low == high
        nums[low] = val;
        return low;
    }
};
