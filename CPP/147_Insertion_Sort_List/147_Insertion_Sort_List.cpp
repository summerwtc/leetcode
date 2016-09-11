/**
147. Insertion Sort List

    Total Accepted: 80554
    Total Submissions: 262329
    Difficulty: Medium

Sort a linked list using insertion sort
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
    ListNode* insertionSortList(ListNode* head) {
        //insertion sort this list
        if(!head) {
            return head;
        }
        ListNode *tail = head;
        ListNode *next = NULL;
        int tempVal = 0;
        
        //just swap the values of the node (node->val)
        while (tail) {
            next = head;
            while(next != tail) {
                if(next->val > tail->val) {
                    //swap the two nodes' values
                    tempVal = next->val;
                    next->val = tail->val;
                    tail->val = tempVal;
                }
                //update next
                next = next->next;
            }
            //update tail
            tail = tail->next;
        }
        return head;
    }
};
