/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution1 {
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

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;
		while(fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}
};
