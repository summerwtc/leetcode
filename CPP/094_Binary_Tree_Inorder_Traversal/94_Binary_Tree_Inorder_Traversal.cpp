/**
Website: https://leetcode.com/problems/binary-tree-inorder-traversal/

    94. Binary Tree Inorder Traversal

    Given a binary tree, return the inorder traversal of its nodes' values.

    For example:
    Given binary tree [1,null,2,3],

       1
        \
         2
        /
       3

    return [1,3,2].

    Note: Recursive solution is trivial, could you do it iteratively?
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
 
 //Method 1
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> answer;
        if (!root) {
            return answer;
        }
    
        TreeNode *curr = root;
        std::stack<TreeNode *>myStack;
    
        while(curr || !myStack.empty()) {
            while(curr) {
                myStack.push(curr);
                curr = curr->left;
            }
            curr = myStack.top();
            myStack.pop();
            answer.push_back(curr->val);
    
            curr = curr->right;
        }
        return answer;
    }
};

//Method 2
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
         std::vector<int>answer;
        if (root) {
            inOrder(root, answer);
        }
        return answer;
    }
    
    void inOrder(TreeNode *root, std::vector<int>& result)
    {
        if (!root) {
            return;
        }
    
        inOrder(root->left, result);
        result.push_back(root->val);
        inOrder(root->right, result);
    }
};
