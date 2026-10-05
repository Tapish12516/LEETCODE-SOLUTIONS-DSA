class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {        
        vector<int> ans;
        stack<int> st;
        vector<int> nge(nums2.size(), -1);
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge[i] = st.top();
            }                                                               //isme 2 arrays banane hai
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    ans.push_back(nge[j]);
                    break;
                }
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         unordered_map<int, int> mp;
//         stack<int> st;
//         for (int i = nums2.size() - 1; i >= 0; i--) {
//             while (!st.empty() && st.top() <= nums2[i]) {
//                 st.pop();
//             }
//             if (st.empty())
//                 mp[nums2[i]] = -1;                               //isme map use ho rha hai 
//             else
//                 mp[nums2[i]] = st.top();
//             st.push(nums2[i]);
//         }
//         vector<int> ans;
//         for (int x : nums1) {
//             ans.push_back(mp[x]);
//         }
//         return ans;
//     }
// };