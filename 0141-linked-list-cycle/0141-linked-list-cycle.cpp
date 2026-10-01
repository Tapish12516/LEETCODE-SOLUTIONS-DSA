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
    bool hasCycle(ListNode *head){
        //hair tortoise approach        floyd's algo 
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){            //O(N) TC and O(1) SC
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         unordered_map<ListNode*, bool> mp;
//         ListNode* temp = head;
//         while (temp != NULL) {                                      //O(NLOGN) TC AND O(N) SC 
//             if (mp[temp] == 1)  return true;
//             mp[temp] = 1;
//             temp = temp->next;
//         }
//         return false;
//     }
// };