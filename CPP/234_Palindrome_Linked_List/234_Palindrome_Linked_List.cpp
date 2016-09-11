/**
website: https://leetcode.com/problems/palindrome-linked-list/

234. Palindrome Linked List

Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) {
            return true;
        }

        ListNode *middle = getMiddle(head);
        
        //middle should not be NULL
        ListNode *newHead = middle->next;
        middle->next = NULL;

        //reverse the list of fast
        newHead = reverseList(newHead);

        while(newHead) {
            if (newHead->val != head->val) {
                return false;
            }
            newHead = newHead->next;
            head = head->next;
        }
        return true;
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
    
    //Reverse list
    ListNode* reverseList(ListNode* head) {
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
