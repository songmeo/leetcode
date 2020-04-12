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
    ListNode* middleNode(ListNode* head) {
        ListNode* tmp = head;
        int size = 1;
        while(tmp->next) {
            size++;
            tmp = tmp->next;
        }
        int mid = size / 2;
        tmp = head;
        while(mid--) {
            tmp = tmp->next;
        }
        return tmp;
    }
};
