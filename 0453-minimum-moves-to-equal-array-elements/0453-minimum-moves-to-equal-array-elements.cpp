class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        for(int n:nums) sum += n;
        int s = *min_element(nums.begin() , nums.end());
        return sum - nums.size()*s;
    }
};