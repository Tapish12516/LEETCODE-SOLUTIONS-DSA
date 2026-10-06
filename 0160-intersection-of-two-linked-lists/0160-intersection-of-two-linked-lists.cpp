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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempa = headA;
        ListNode* tempb = headB;
        while (tempa != tempb) {
            tempa = (tempa != nullptr) ? tempa->next : headB;           //optimal 
            tempb = (tempb != nullptr) ? tempb->next : headA;
        }
        return tempa;        
    }
};

// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* tempA = headA;
//         while (tempA != NULL) {
//             ListNode* tempB = headB;
//             while (tempB != NULL) {
//                 if (tempA == tempB)  return tempA;               //bruteforce solution
//                 tempB = tempB->next;
//             }
//             tempA = tempA->next;
//         }
//         return NULL;
//     }
// };