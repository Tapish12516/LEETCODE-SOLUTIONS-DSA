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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next || left == right) {
            return head;
        }
        ListNode* left1 = head;
        for (int i = 1; i < left - 1; i++) {
            left1 = left1->next;
        }
        ListNode* prevl;
        if (left == 1) {
            prevl = nullptr;
            left1 = head;
        } else {
            prevl = left1;
            left1 = left1->next;
        }
        ListNode* right1 = head;
        for (int i = 1; i < right; i++) {
            right1 = right1->next;
        }
        ListNode* rightn = right1->next;
        ListNode* curr = left1;
        ListNode* prev1 = rightn;
        ListNode* next1 = nullptr;
        while (curr != rightn) {
            next1 = curr->next;
            curr->next = prev1;
            prev1 = curr;
            curr = next1;
        }
        if (prevl) {
            prevl->next = prev1;
        } else {
            head = prev1;
        }
        return head;
    }
};