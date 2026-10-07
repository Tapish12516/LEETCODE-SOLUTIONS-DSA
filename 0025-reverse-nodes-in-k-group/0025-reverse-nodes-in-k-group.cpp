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
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* curr = head;
//         ListNode* prev = NULL;
//         while(curr != NULL){
//             ListNode* next1 = curr->next;           //iterative approach ||classic
//             curr->next = prev;
//             prev = curr;
//             curr = next1;
//         }
//         return prev;
//     }
//     ListNode* reverseKGroup(ListNode* head, int k) {
        
//     }
// };


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 1) {
            return head;
        }
        ListNode* temp = head; 
        for (int i = 0; i < k; i++) {
            if (temp == nullptr) {
                return head;
            }
            temp = temp->next;
        }
        ListNode* previous = nullptr;
        ListNode* current = head;
        for (int i = 0; i < k; i++) {
            ListNode* front = current->next;
            current->next = previous;
            previous = current;
            current = front;
        }
        head->next = reverseKGroup(current, k); 
        return previous;
    }
};