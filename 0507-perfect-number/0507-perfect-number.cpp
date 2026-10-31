class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        long long sum = 0;
        for(int i = 1 ; i < sqrt(num); i++){
            if(num%i == 0){
                sum+=i;
                if(i!=1 && i!=num/i) sum+= num/i;
            }
        }
        return sum == num;
    }
};

// Important DSA concept: Whenever you iterate up to sqrt(n) to find factors, remember that factors come in pairs: i and n/i.