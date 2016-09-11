/**
WebSite: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

    82. Remove Duplicates from Sorted List II

    Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

    For example,
    Given 1->2->3->3->4->4->5, return 1->2->5.
    Given 1->1->1->2->3, return 2->3. 
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
        if (!head || !head->next) {
            return head;
        }
    
        ListNode newNode(0);
        ListNode *pNewNode = &newNode;
    
        ListNode *prev = pNewNode;
        ListNode *curr = head;
        ListNode *temp = NULL;
        bool deleteFlag = false;
    
        while(curr) {
            //delete the nodes with same value 
            while (curr->next && (curr->val == curr->next->val)) {
                deleteFlag = true;
                //delete curr->next
                temp = curr->next->next;
                delete curr->next;
                curr->next = temp;
            }
    
            //using deleteFlag to judge where the curr node should be deleted or not
            if (deleteFlag) {
                //delete curr
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
            //update deleteFlag        
            deleteFlag = false;
        }
    
        //return list head
        return pNewNode->next;
    }
};
