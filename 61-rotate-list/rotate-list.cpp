/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        int c = 0;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (curr != nullptr) {
            c++;
            prev = curr;
            curr = curr->next;
        }
        prev -> next = head;
        k = k % c;
        curr = head;
        for (int i=0; i<(c-k-1); i++) {
            curr = curr -> next;
        }
        head = curr -> next;
        curr -> next = NULL;
        return head;
    }
};