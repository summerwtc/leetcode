/***
WebSite: https://leetcode.com/problems/delete-node-in-a-linked-list/
237. Delete Node in a Linked List

    Total Accepted: 101175
    Total Submissions: 227349
    Difficulty: Easy

Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, 
the linked list should become 1 -> 2 -> 4 after calling your function. 

*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //Because the node is not the tail, node->next should not be NULL
        ListNode *temp = node->next;  
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
        temp = NULL;
    }
};
