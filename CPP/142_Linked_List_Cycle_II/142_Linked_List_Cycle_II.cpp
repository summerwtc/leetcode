/***
WebSite: https://leetcode.com/problems/linked-list-cycle-ii/

142. Linked List Cycle II

    Total Accepted: 85487
    Total Submissions: 273154
    Difficulty: Medium

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space? 
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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
        return NULL;
        }

        //using fast pointer ans slow pointer
        ListNode *fast = head;
        ListNode *slow = head;

        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                //It has cycle, Now fast pointer points to head
                fast = head;
                while (fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                //Now fast and slow are both pointing to the node where the cycle begins 
                return slow;
            }
        }
        //there is no cycle in this list
        return NULL;
    }
};
