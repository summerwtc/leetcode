/**
WebSite: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

83. Remove Duplicates from Sorted List

    Total Accepted: 135577
    Total Submissions: 358194
    Difficulty: Easy

Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. 
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
		    return head;
	    }

	    ListNode *curr = head;
	    ListNode *next = head->next;
	    while (next) {
		    //compare two values for equality, if they are equal, delete the latter
		    if (next->val == curr->val) {
			    curr->next = next->next;
			    delete next;
			    next = curr->next;
		    } else {
			    curr = curr->next;
			    next = curr->next;
		    }
	    }
	    return head;
    }
};