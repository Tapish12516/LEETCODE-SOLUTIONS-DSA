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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* newhead =  reverseList(head->next);
        ListNode* front = head->next;                           //recursive approach 
        front->next = head;
        head->next = nullptr;
        return newhead;
    }
};
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
// };