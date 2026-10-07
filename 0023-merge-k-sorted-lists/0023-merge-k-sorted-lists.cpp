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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        vector<int> values;
        for(auto horizontal: lists){
            ListNode* vertical = horizontal;
            while(vertical){
                values.push_back(vertical->val);
                vertical = vertical->next;
            }
        }
        sort(values.begin() , values.end());                    //better solution O(nlogn) and O(n)
        ListNode dumpy(0);
        ListNode* temp = &dumpy;
        for(int value:values){
            temp->next = new ListNode(value);
            temp = temp->next;
        }
        return dumpy.next;
    }
};