class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        for (int x : nums1) {
            if (x % 2)
                minOdd = min(minOdd, x);
        }
        if(minOdd == INT_MAX) minOdd = INT_MIN;
        for (int x : nums1) {
            if (x % 2 == 0 && x <= minOdd)
                return false;
        }
        return true;
    }
};