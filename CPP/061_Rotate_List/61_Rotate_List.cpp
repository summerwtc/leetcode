/***
WebSite: https://leetcode.com/problems/rotate-list/


61. Rotate List
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

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
    ListNode* rotateRight(ListNode* head, int k) {
    	if (!head || !head->next) {
    		return head;
    	}

    	//In case that list len is smaller than k
    	int itemNum = getListLen(head);
    	k = k % itemNum;

    	//Don't need to rotate the list
    	if (0 == k) {
    		return head;
    	}

    	ListNode *temp = NULL;
    	ListNode *newHead = head;

    	for (int i = 0; i < itemNum - k; ++i) {
    		temp = newHead;
    		newHead = newHead->next;
    	}
	
    	//Now newHead points to the head of new list
    	temp->next = NULL;
    	temp = newHead;
    	while(temp->next){ 
    		temp = temp->next;
    	}
    	temp->next = head;

    	return newHead;
    }
    
    int  getListLen(ListNode *head)
    {
	    if (!head) {
		    return 0;
	    }

	    int itemNum = 0;
	    while(head) {
		    ++itemNum;
		    head = head->next;
	    }
	    return itemNum;
    }
};