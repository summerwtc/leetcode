/**
WebSite: https://leetcode.com/problems/swap-nodes-in-pairs/
24. Swap Nodes in Pairs

    Total Accepted: 116859
    Total Submissions: 321969
    Difficulty: Easy

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed. 

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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) {
		    return head;
	    }

	    //swap the val of every two adjacent nodes
	    ListNode *curr = head;
	    ListNode *next = NULL;
	    int tempVal = 0;

	    while(curr && curr->next) {
		    next = curr->next;

		    //swap the two value: next->val and curr->val
		    tempVal = curr->val;
		    curr->val = next->val;
		    next->val = tempVal;

		    //update curr
		    curr = curr->next->next;
	    }
	    return head;
    }
};