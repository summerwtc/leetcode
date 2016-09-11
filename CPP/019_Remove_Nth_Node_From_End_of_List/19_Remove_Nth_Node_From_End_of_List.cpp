/**
WebSite: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

19. Remove Nth Node From End of List

    Total Accepted: 127178
    Total Submissions: 411684
    Difficulty: Easy

Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n < 0) {
		    return NULL;
	    }
	    if (!head || 0 == n ) {
		    return head;
	    }
		
		//using fast and slow pointers, the fast points to the last node,
		//and slow->next point to the Nth Node
	    ListNode *fast = head;
	    ListNode *slow = head;

	    while (n-- && (fast)) {
		    fast = fast->next;
	    }

	    //if fast is NULL, the head should be delete
	    if (!fast) {
		    head = head->next;
		    delete slow;
		    slow = NULL;
		    return head;
	    }

	    while(fast->next) {
		    fast = fast->next;
		    slow = slow->next;
	    }
	    //the Nth node is slow->next, and delete it
	    fast = slow->next;
	    slow->next = slow->next->next;
	    delete fast;
	    fast = NULL;

	    return head;
    }
};