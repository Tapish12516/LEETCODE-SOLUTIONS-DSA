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
    ListNode* reverselist(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr != NULL){
            ListNode* next1 = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next1;
        }
        return prev;
    }
    ListNode* rkthnode(ListNode* curr , int k){
        while(curr != NULL && k>1){
            curr = curr->next;
            k--;
        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k <= 1) {
            return head;
        }
        ListNode* temp = head;
        ListNode* prevlast = nullptr;
        while(temp){
            ListNode* kth = rkthnode(temp , k);
            if (kth == nullptr) {
                if (prevlast != nullptr) {
                    prevlast->next = temp;                  //optimal solution O(N) and O(1)
                }
                break;
            }
            ListNode* nextgrp = kth->next;
            kth->next = nullptr;
            reverselist(temp);
            if (temp == head)  head = kth;
            else  prevlast->next = kth;
            prevlast = temp;
            temp = nextgrp;
        }
        return head;
    }
};


// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         if (head == nullptr || k <= 1) {
//             return head;
//         }
//         ListNode* temp = head; 
//         for (int i = 0; i < k; i++) {
//             if (temp == nullptr) {
//                 return head;
//             }
//             temp = temp->next;                       //better solution
//         }
//         ListNode* previous = nullptr;
//         ListNode* current = head;
//         for (int i = 0; i < k; i++) {
//             ListNode* front = current->next;
//             current->next = previous;
//             previous = current;
//             current = front;
//         }
//         head->next = reverseKGroup(current, k); 
//         return previous;
//     }
// };