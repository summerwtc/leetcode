/**
Website: https://leetcode.com/problems/reverse-linked-list-ii/

	92. Reverse Linked List II

	Reverse a linked list from position m to n. Do it in-place and in one-pass.

	For example:
	Given 1->2->3->4->5->NULL, m = 2 and n = 4,

	return 1->4->3->2->5->NULL.

	Note:
	Given m, n satisfy the following condition:
	1 ¡Ü m ¡Ü n ¡Ü length of list. 
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || (m == n)) {
    		return head;
    	}
    
    	ListNode *fast = head;
    	//get fast position, and fast points to the nth node
    	for(int i = 0; i < n - 1; ++i) {
    		fast = fast->next;
    	}
    	//save fast->next
    	ListNode *fastNext = fast->next;
    	//set fast->next value to null
    	fast->next = NULL;
    	
    	ListNode *slow = head;
    	ListNode *prev = NULL;
    	//get slow position, and slow points to the mth node
    	for(int i = 0; i < m - 1; ++i) {
    		prev = slow;
    		slow = slow->next;
    	}
    
    	//reverse the list from slow to fast
    	ListNode *newHead = reverseList(slow);
    
    	//slow points to the tail of new list, update slow->next,
    	slow->next = fastNext;
    
    	if (prev) {
    		prev->next = newHead;
    	} else {
    		head = newHead;
    	}
    
    	return head;
    }
    
    //reverse list
    ListNode* reverseList(ListNode* head)
    {
    	if (!head || !head->next) {
    		return head;
    	}
    	//using three pointer, prev points to previous node,
    	//curr points to the current node, and next points to next node
    	ListNode *prev = NULL;
    	ListNode *curr = head;
    	ListNode *next = NULL;
    	while(curr->next) {
    		next = curr->next;
    		curr->next = prev;
    		prev= curr;
    		curr = next;
    	}
    	//reset the value of curr->next
    	curr->next = prev;
    	return curr;
    }
};