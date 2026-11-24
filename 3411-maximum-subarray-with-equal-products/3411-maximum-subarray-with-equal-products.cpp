class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            long long prod = 1;
            long long gcd = nums[i];
            long long lcm = nums[i];
            for(int j = i; j < nums.size(); j++) {
                if (prod > LLONG_MAX / nums[j]) break;
                prod *= nums[j];
                gcd = std::gcd(gcd, (long long)nums[j]);
                lcm = std::lcm(lcm, (long long)nums[j]);
                if(prod == gcd * lcm)
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};