/**

203. Remove Linked List Elements

    Total Accepted: 77481
    Total Submissions: 258325
    Difficulty: Easy

Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5 

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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *curr = NULL;

        //find the first node whose val is not equal to val 
        while(head) {
            if (head->val == val) {
                prev = head;
                head = head->next;
                delete prev;
            } else {
                break;
            }
        }
        if (!head) {
            return NULL;
        }
        //now head->val != val
        prev = head;
        curr = head->next;
        while(curr) {
            if(curr->val == val) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
