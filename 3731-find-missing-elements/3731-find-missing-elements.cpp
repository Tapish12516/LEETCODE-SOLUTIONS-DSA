class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int> ans;
        for (int i = 0; i < n - 1; i++) {                               //better approach
            for (int j = nums[i] + 1; j < nums[i + 1]; j++) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<int> findMissingElements(vector<int>& nums) {
//             int mn = *min_element(nums.begin(), nums.end());
//             int mx = *max_element(nums.begin(), nums.end());
//             unordered_set<int> st(nums.begin(), nums.end());
//             vector<int> ans;
//             for (int x = mn + 1; x < mx; x++) {
//                 if (!st.count(x))  ans.push_back(x);
//             }
//         return ans;
//     }
// };