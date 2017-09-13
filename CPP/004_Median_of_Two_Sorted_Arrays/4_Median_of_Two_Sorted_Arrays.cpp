/*
  websit: https://leetcode.com/problems/median-of-two-sorted-arrays/description/

  4. Median of Two Sorted Arrays

  There are two sorted arrays nums1 and nums2 of size m and n respectively.

  Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

  Example 1:
  nums1 = [1, 3]
  nums2 = [2]

  The median is 2.0
  Example 2:
  nums1 = [1, 2]
  nums2 = [3, 4]

  The median is (2 + 3)/2 = 2.5

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int total = nums1.size() + nums2.size();

        if (total % 2 == 0) {
            double result1 = findKth(nums1, nums1.begin(), nums2, nums2.begin(),  (total / 2)  + 1);
            double result2 = findKth(nums1, nums1.begin(), nums2, nums2.begin(),  total / 2);
            return (result1 + result2) / 2;

        } else {
            return findKth(nums1, nums1.begin(), nums2, nums2.begin(), (total + 1) / 2);
        }
    }
    
    //find the the kth value
    double findKth(vector<int> &nums1, vector<int>::iterator begin1,
                   vector<int> &nums2, vector<int>::iterator begin2, int kth)
    {
        int sizeN1 = nums1.end() - begin1;
        int sizeN2 = nums2.end() - begin2;

        if ( sizeN1 > sizeN2) {
            return findKth(nums2, begin2, nums1, begin1, kth);
        }

        if (0 == sizeN1) {
            return *(begin2 + kth - 1);
        }

        if (1 == kth) {
            return min(*begin1, *begin2);
        }

        int partN1 = min(kth / 2, sizeN1);
        int partN2 = kth - partN1;

        if (*(begin1 + partN1 - 1) < *(begin2 + partN2 - 1)) {
            return findKth(nums1, begin1 + partN1, nums2, begin2, kth - partN1);
        } else {
            return findKth(nums1, begin1, nums2, begin2 + partN2, kth - partN2); 
        }
    }
};
