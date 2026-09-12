class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)                        // Recursive approach O(2^N)
            return n;
        return fib(n - 1) + fib(n - 2);
    }
};

