/**
webset: https://leetcode.com/problems/intersection-of-two-linked-lists/

160. Intersection of Two Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 �� a2
                   �K
                     c1 �� c2 �� c3
                   �J            
B:     b1 �� b2 �� b3

begin to intersect at node c1.

Notes:

    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {
            return NULL;
        }

        int lenA = getListLen(headA);
        int lenB = getListLen(headB);
        ListNode *currA = headA;
        ListNode *currB = headB;

        if (lenA > lenB) {
            for(int i = 0; i < lenA-lenB; ++i) {
                currA = currA->next;
            }
        } else {
            for (int i = 0; i < lenB - lenA; ++i) {
                currB = currB->next;
            }
        }

        while(currA) {
            if (currA->val != currB->val) {
                currA = currA->next;
                currB = currB->next;
            } else {
                return currA;
            }
        }
        return NULL;
    }
    
    //get List len
    int getListLen(ListNode *head)
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