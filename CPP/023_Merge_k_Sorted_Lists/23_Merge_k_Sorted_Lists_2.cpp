/**
website: https://leetcode.com/problems/merge-k-sorted-lists/

    23. Merge k Sorted Lists

    Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //using merge sort method
        if (lists.empty()) {
            return NULL;
        }
        if (1 == lists.size()) {
            return lists.front();
        }
        vector<int>::size_type middle = (lists.size() + 1) / 2;

        vector<ListNode *> firstLists(lists.begin(), lists.begin() + middle);
        vector<ListNode *> secondLists(lists.begin() + middle, lists.end());
    
        ListNode *first = mergeKLists(firstLists);
        ListNode *second = mergeKLists(secondLists);
        
        //merge two sorted lists
        return mergeTwoLists(first, second);
    }
    
    //merge two sorted lists
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
};
