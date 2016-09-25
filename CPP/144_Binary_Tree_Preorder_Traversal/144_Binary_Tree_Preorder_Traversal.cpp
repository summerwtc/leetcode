/**
    144. Binary Tree Preorder Traversal

    Given a binary tree, return the preorder traversal of its nodes' values.

    For example:
    Given binary tree {1,#,2,3},

       1
        \
         2
        /
       3

    return [1,2,3].

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
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> answer;
        if (!root) {
            return answer;
        }
    
        TreeNode *curr = root;
        std::stack<TreeNode *>myStack;
    
        while(curr || !myStack.empty()) {
            while(curr) {
                //save value
                answer.push_back(curr->val);
                myStack.push(curr);
                curr = curr->left;
            }
            
            curr = myStack.top();
            myStack.pop();
            curr = curr->right;
        }
        return answer;
    }
};

//Method 2
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> answer;
        if (!root) {
            return answer; 
        }
        std::stack<TreeNode *>myStack;
        TreeNode *curr = NULL;
    
        myStack.push(root);
        while(!myStack.empty()) {
            curr = myStack.top();
            myStack.pop();
            answer.push_back(curr->val);
    
            if (curr->right) {
                myStack.push(curr->right);
            }
            if (curr->left) {
                myStack.push(curr->left);
            }
        }
        return answer;
    }
};

//Method 3
//Recursive solution 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> answer;
        preOrder(root, answer);
        return answer;
    }
    
    //Recursive solution 
    void preOrder(TreeNode *root, std::vector<int>& result)
    {
        if (!root) {
            return;
        }
        result.push_back(root->val);
        preOrder(root->left, result);
        preOrder(root->right, result);
    }
};
