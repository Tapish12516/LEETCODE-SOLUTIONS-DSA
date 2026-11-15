class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long even = 1, odd = 0;
        long long prefix = 0;
        long long mod = 1e9 + 7;
        for (int x : arr) {
            prefix += x;
            if (prefix % 2 == 0)
                even++;
            else
                odd++;
        }
        return (even * odd) % mod;
    }
};
