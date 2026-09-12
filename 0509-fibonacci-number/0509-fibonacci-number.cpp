class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)
            return n;
        int x1 = 0;     //n-2
        int x2 = 1;    //n-1
        int cur ;                                        // using simple for loop
        for(int i = 2 ; i<=n ; i++){                    // TC is O(N) and SC is O(1)
            cur = x1 + x2;
            x1 = x2;
            x2 = cur;
        }
        return cur;
    }
};

// class Solution {
// public:
//     int fib(int n) {
//         if (n == 0 || n == 1)                        // Recursive approach O(2^N)
//             return n;
//         return fib(n - 1) + fib(n - 2);
//     }
// };