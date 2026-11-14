class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                int len = j - i + 1;
                if (len >= l && len <= r && sum > 0) {
                    ans = min(ans, sum);
                }
                if (len >= r) break;
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};


// class Solution {
// public:
//     int minimumSumSubarray(vector<int>& nums, int l, int r) {
//         int n = nums.size();
//         vector<long long> pref(n + 1, 0);
//         for (int i = 0; i < n; i++) {
//             pref[i + 1] = pref[i] + nums[i];
//         }
//         multiset<long long> st;
//         long long ans = LLONG_MAX;
//         for (int i = l; i <= n; i++) {
//             st.insert(pref[i - l]);
//             if (i - r - 1 >= 0) {
//                 auto it = st.find(pref[i - r - 1]);
//                 if (it != st.end())
//                     st.erase(it);
//             }
//             auto it = st.lower_bound(pref[i]);
//             if (it != st.begin()) {
//                 --it;
//                 ans = min(ans, pref[i] - *it);
//             }
//         }
//         return ans == LLONG_MAX ? -1 : (int)ans;
//     }
// };