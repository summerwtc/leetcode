/**
Website: https://leetcode.com/problems/sort-list/

148. Sort List

Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        ListNode *middle = getMiddle(head);
        //middle is not null, break down into two lists 
        ListNode *newHead = middle->next;
        middle->next = NULL;
        head = sortList(head);
        newHead = sortList(newHead);

        return mergeTwoLists(head, newHead);
    }
    
    //merge two sorted list
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if(!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }
    
        ListNode *newHead = NULL;
        ListNode *tail  = NULL;
    
        //get the newHead 
        if (l1->val < l2->val) {
            newHead= l1;
            l1 = l1->next;
        } else {
            newHead = l2;
            l2 = l2->next;
        }
        tail = newHead;
    
        while(l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        
        if(!l1) {
            tail->next = l2;
        } else {
            tail->next = l1;
        }
        return newHead;
    }
    
    //get the middle position of the list
    ListNode * getMiddle(ListNode *head)
    {
        if (!head || !head->next) {
            return head;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        
        //use fast and slow pointers, fast moves two steps, and slow move one step.
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        //Now slow points to the middle of the list
        return slow;
    }
};
