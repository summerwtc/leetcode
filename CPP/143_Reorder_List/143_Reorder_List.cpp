/**
Website: https://leetcode.com/problems/reorder-list/

143. Reorder List

Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}. 
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
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
    
        //break into two lists
        ListNode *first = getMiddle(head);
        ListNode *secondHead = first->next;
        first->next = NULL;
    
        //reverse the second list
        secondHead = reverseList(secondHead);
    
        first = head;
        ListNode *tempFirst = NULL;
        ListNode *tempSeond = NULL;
        //the node number in first list is larger or equal to that in second list
        //merge the two lists
        while(secondHead) {
            tempFirst = first->next;
            tempSeond = secondHead->next;
            first->next = secondHead;
            secondHead->next = tempFirst;
            first = tempFirst;
            secondHead = tempSeond;
        }
    }
    
    //reverse the list
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
    
    //get the middle position of the list
    ListNode * getMiddle(ListNode *head)
    {
        if (!head || !head->next) {
            return head;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        
        //use fast and slow pointers
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        //Now slow points to the middle of the list
        return slow;
    }
};
