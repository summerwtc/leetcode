/**
WebSite: https://leetcode.com/problems/add-two-numbers/

    2. Add Two Numbers

        Total Accepted: 176209
        Total Submissions: 709999
        Difficulty: Medium

    You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) {
            return l2;
        }
        if (!l2) {
            return l1;
        }

        ListNode *head = NULL;
        ListNode *tail = NULL;
        ListNode *pNewNode = NULL;
        int sum = 0;

        while (l1 || l2) {
            if (l1) {
                sum += l1->val;
            }
            if (l2){
                sum += l2->val;
            }

            pNewNode = new ListNode(sum % 10);
            if (NULL == pNewNode) {
                return NULL;
            }

            if (head) {
                tail->next = pNewNode;
                tail = tail->next;
            } else {
                head = pNewNode;
                tail = head;
            }
            //update sum
            sum = sum /10;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (sum) {
            pNewNode = new ListNode(sum % 10);
            if (NULL == pNewNode) {
                return NULL;
            }
            tail->next = pNewNode;
            tail = tail->next;
        }
        return head;
    }
};
