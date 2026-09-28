class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int i;
        for (i = 0; i < n; i++) {
            if (nums[i] == mn || nums[i] == mx)  break;
        }
        int j;
        for (j = n - 1; j >= 0; j--) {
            if (nums[j] == mn || nums[j] == mx)  break;
        }
        int left = j + 1;
        int right = n - i;
        int both = (i + 1) + (n - j);
        right = min(right, both);
        return min(left, right);
    }
};
