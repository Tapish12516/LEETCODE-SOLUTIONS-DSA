class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = k;
        while (st.count(ans)) {                             //O(N) TC and O(N) SC
            ans += k;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int missingMultiple(vector<int>& nums, int k) {
//         int minmul = 0;
//         if(nums[0]%k == 0) minmul = nums[0];
//         for(int i = 1; i <nums.size()-1 ;i++){
//             if(minmul<nums[i] && nums[i]%k==0) minmul = nums[i];
//         }
//         if(!minmul) return k;
//         else return minmul+k;
//         return k;
//     }
// };

// class Solution {
// public:
//     int missingMultiple(vector<int>& nums, int k) {
//         int ans = k;
//         while (true) {
//             bool found = false;
//             for (int i = 0; i < nums.size(); i++) {
//                 if (nums[i] == ans) {
//                     found = true;                       //O(N^2) solution in worst case but can be used bec of constraints
//                     break;
//                 }
//             }
//             if (!found) return ans;
//             ans += k;
//         }
//         return ans;
//     }
// };