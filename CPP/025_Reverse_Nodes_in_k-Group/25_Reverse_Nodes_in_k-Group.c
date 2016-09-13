/**
Website: https://leetcode.com/problems/reverse-nodes-in-k-group/

	25. Reverse Nodes in k-Group

	Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

	If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

	You may not alter the values in the nodes, only nodes itself may be changed.

	Only constant memory is allowed.

	For example,
	Given this linked list: 1->2->3->4->5

	For k = 2, you should return: 2->1->4->3->5

	For k = 3, you should return: 3->2->1->4->5 
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k <= 1) {
    		return head;
    	}
    
    	ListNode newNode(0);
    	ListNode *prevHead = &newNode;
    	prevHead->next = head; 
    
    	ListNode *start = head;
    	ListNode *end = head;
    	int count = 1;
    	while (end) {
    		if (count < k) {
    			end = end->next;
    			++count;
    		} else {
    			ListNode *next = end->next;
    			end->next = NULL;
    			//reverse list 
    			prevHead->next = reverseList(start);
    			//update prevHead
    			prevHead = start;
    			start->next = next;
    			start = end = next;
    			count = 1;
    		}
    	}
    	//return head
    	return newNode.next;
    }
    
	//reverse list
    ListNode* reverseList(ListNode* head)
    {
    	if (!head) {
    		return head;
    	}
    
    	ListNode *next = NULL;
    	ListNode *newHead = NULL;
    
    	//insert node before head
    	while (head) {
    		next = head->next;
    		head->next = newHead;
    		newHead = head;
    		head = next;
    	}
    	return newHead;
    }
};