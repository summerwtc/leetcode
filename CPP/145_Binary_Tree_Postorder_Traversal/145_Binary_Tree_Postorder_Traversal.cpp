/**
WebSite: https://leetcode.com/problems/binary-tree-postorder-traversal/

    145. Binary Tree Postorder Traversal

    Given a binary tree, return the postorder traversal of its nodes' values.

    For example:
    Given binary tree {1,#,2,3},

       1
        \
         2
        /
       3

    return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> answer;
        if (!root) {
            return answer;
        }
        TreeNode *curr = root;
        TreeNode *prev = NULL;  //prev points to the previous visited TreeNode
        std::stack<TreeNode *>myStack;
    
        while (curr || !myStack.empty()) {
            while (curr) {
                myStack.push(curr);
                curr = curr->left;
            }
            curr = myStack.top();
            //if the curr's right child is NULL, or the curr's right child had been visited, 
            //visited the curr
            if (!curr->right || (prev == curr->right)) {
                myStack.pop();
                //save value
                answer.push_back(curr->val);
                //update prev
                prev = curr;
                curr = NULL;
            } else {
                curr = curr->right;
            }
        }
        return answer;
    }
};


//Method 2:
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> answer;
        if (root) {
            postOrder(root, answer);
        }
        return answer;
    }
    
    void postOrder(TreeNode *root, std::vector<int> &result)
    {
        if (!root) {
            return;
        }
        postOrder(root->left, result);
        postOrder(root->right, result);
        result.push_back(root->val);
    }
};

//Method 3
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> answer;
        if (!root) {
            return answer;
        }
    
        TreeNode *curr = root;
        std::stack<TreeNode *>myStack;
        
        //visited right child before left child
        while(curr || !myStack.empty()) {
            while(curr) {
                //save value
                answer.push_back(curr->val);
                myStack.push(curr);
                curr = curr->right;
            }
            curr = myStack.top();
            //answer.push_back(curr->val);
            myStack.pop();
            curr = curr->left;
        }
        //reverse answer
        std::reverse(answer.begin(), answer.end());
        return answer;
    }
};
