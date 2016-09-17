/**
Website: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

    108. Convert Sorted Array to Binary Search Tree

    Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) {
            return NULL;
        }
        return buildTree(nums, 0, nums.size() - 1);
    }
    
    //Recursive to create a new binary tree
    TreeNode *buildTree(vector<int>& nums, int start, int end)
    {
        if (start > end) {
            return NULL;
        }
    
        int middle = (end + start)/2;
    
        TreeNode *pNew = new TreeNode(nums[middle]);
        if (NULL == pNew) {
            return NULL;
        }
        pNew->left = buildTree(nums, start, middle-1);
        pNew->right = buildTree(nums, middle + 1, end);
        return pNew;
    }
};
