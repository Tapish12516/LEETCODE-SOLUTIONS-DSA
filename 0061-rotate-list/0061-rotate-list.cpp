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
        if( !head || !head->next || k==0) return head;
        int length = 1;
        ListNode* tail = head;
        while(tail->next){
            tail = tail->next;
            length++;
        }
        tail->next = head;          //circular bana diya 
        k = k % length;
        int steps= length-k;
        ListNode* newtail= head;
        for (int i = 1; i < steps; i++)  newtail = newtail->next;
        ListNode* newHead = newtail->next;
        newtail->next = NULL;
        return newHead;
    }
};