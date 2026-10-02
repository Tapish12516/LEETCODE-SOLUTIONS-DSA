class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        long long start = 1000;
        while (start <= n) {                    //O(logn) but valid for largest n also.
            total += n - start + 1;
            start *= 1000;
        }
        return total;
    }
};