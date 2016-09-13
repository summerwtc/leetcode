/**
webset: https://leetcode.com/problems/reverse-linked-list/

206. Reverse Linked List

    Total Accepted: 137078
    Total Submissions: 330662
    Difficulty: Easy

Reverse a singly linked list.

click to show more hints.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//method one:

class Solution {
public:
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


//method two:
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return head;
        }
    
        ListNode *temp = NULL;
        ListNode *newHead = NULL;
    
        //insert node before head
        while (head) {
            temp = head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }
        return newHead;
    }
};
