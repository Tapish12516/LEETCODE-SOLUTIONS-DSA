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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head->next)
            return nullptr;
        ListNode* temp = head;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }
        if (count == n) {
            ListNode* ptr = head;
            head = head->next;
            delete ptr;
            return head;
        }
        temp = head;
        for (int i = 1; i < count - n; i++) {
            temp = temp->next;
        }
        ListNode* ptr = temp->next;
        temp->next = temp->next->next;
        delete ptr;
        return head;
    }
};