class Solution {
public:
    // int firstOccurrence(vector<int>& nums, int target) {
    //     int low = 0;
    //     int high = nums.size() - 1;
    //     int ans = -1;
    //     while (low <= high) {
    //         int mid = low + (high - low) / 2;
    //         if (nums[mid] == target) {
    //             ans = mid;
    //             high = mid - 1;
    //         }
    //         else if (nums[mid] > target)  high = mid - 1;
    //         else  low = mid + 1;
    //     }
    //     return ans;
    // }

    // int lastOccurrence(vector<int>& nums, int target) {
    //     int low = 0;
    //     int high = nums.size() - 1;
    //     int ans = -1;
    //     while (low <= high) {
    //         int mid = low + (high - low) / 2;
    //         if (nums[mid] == target) {
    //             ans = mid;
    //             low = mid + 1;
    //         }
    //         else if (nums[mid] > target)  high = mid - 1;
    //         else  low = mid + 1;
    //     }
    //     return ans;
    // }

    vector<int> searchRange(vector<int>& nums, int target) {
        // int first = firstOccurrence(nums, target);
        // int last = lastOccurrence(nums, target);

        int lb = lower_bound(nums.begin(), nums.end(),target) - nums.begin();
        if (lb == nums.size() || nums[lb] != target) {
            return {-1, -1}; 
        }
        int ub = upper_bound(nums.begin(), nums.end(), target)- nums.begin();
        return {lb, ub-1};
    }
};


//we can diectly use the concept of lower and upper bound to this problem 