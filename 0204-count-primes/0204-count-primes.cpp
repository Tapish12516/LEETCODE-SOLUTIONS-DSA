class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        vector<bool> composite(n, false);
        int count = n / 2;
        for (int i = 3; 1LL * i * i < n; i += 2) {
            if (!composite[i]) {
                for (long long j = 1LL * i * i; j < n; j += 2 * i) {            //sieve approach
                    if (!composite[j]) {
                        composite[j] = true;
                        count--;
                    }
                }
            }
        }
        return count;
    }
};



// class Solution {
// public:
//     int countPrimes(int n) {
//         if(n==0||n==1) return 0;
//         int prime = 0;
//         for(int i = 2 ; i < n ; i++) {
//             bool isprime = true;
//             for(int j = 2 ; j <=  sqrt(i) ; j++ ){       //O(n*root(n))
//                 if( i%j == 0) {
//                     isprime = false;
//                     break;
//                 }
//             } 
//             if( isprime ) prime++;
//         }
//         return prime;
//     }
// };