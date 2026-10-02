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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        while(head != NULL){
            ListNode* next = head -> next;      //more efficient for space using no stack
            head-> next = prev;
            prev =head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow = reverse(slow);                               //playing in slow and fast is more efficient
        fast =head;                   //reversing second half again in last is not necessary acd to given constraints
        while(slow != NULL){
        if(slow->val != fast->val) return false;
        slow = slow->next;
        fast = fast->next;
        }  
        return true;
    }
};


    // ListNode* reverseList(ListNode* head) {
    //     if (head == NULL || head->next == NULL)  return head;
    //     ListNode* newhead = reverseList(head->next);
    //     head->next->next = head;                                 //recursive taking more space 
    //     head->next = NULL;
    //     return newhead;
    // }