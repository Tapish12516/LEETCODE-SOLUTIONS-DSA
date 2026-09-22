class Solution {
public:
    bool isMonotonic(std::vector<int>& nums) {
        bool is_increasing = true;
        bool is_decreasing = true;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1])
                is_decreasing = false;
            else if (nums[i] < nums[i - 1])
                is_increasing = false;
            if (!is_increasing && !is_decreasing)
                return false;
        }
        return is_increasing || is_decreasing;
    }
};