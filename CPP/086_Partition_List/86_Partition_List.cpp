/**
Website: https://leetcode.com/problems/partition-list/

    86. Partition List

    Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

    You should preserve the original relative order of the nodes in each of the two partitions.

    For example,
    Given 1->4->3->2->5->2 and x = 3,
    return 1->2->2->4->3->5. 
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
    ListNode* partition(ListNode* head, int x) {
        if(!head) {
            return head;
        }
        //using two lists to save the nodes
        ListNode *smallerHead = NULL;
        ListNode *smaller = NULL;
        ListNode *equalLargerHead = NULL;
        ListNode *equalLarger = NULL;
    
        while (head) {
            if(head->val < x) {
                //update list that smaller than x
                if (smallerHead) {
                    smaller->next = head;
                    smaller = smaller->next;
                } else {
                    smallerHead = head;
                    smaller = smallerHead;
                }
            } else {
                //update list that larger or equal to x
                if(equalLargerHead) {
                    equalLarger->next = head;
                    equalLarger = equalLarger->next;
                } else {
                    equalLargerHead = head;
                    equalLarger = equalLargerHead;
                }
            }
            head = head->next;
        }
        
        if (equalLargerHead) {
            //update equalLarger
            equalLarger->next = NULL;
        }
    
        if (smallerHead) {
            smaller->next = equalLargerHead;
            return smallerHead;
        } else {
            return equalLargerHead;
        }
    }
};
