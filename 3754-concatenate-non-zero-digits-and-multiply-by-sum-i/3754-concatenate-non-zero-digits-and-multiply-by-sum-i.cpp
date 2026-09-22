class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0 ;
        int sum = 0; 
        int place = 1;
        while( n > 0 ){
            int dig = n%10;
            if(dig != 0) { x = x + dig*place;
            place = place*10; }
            n = n/10;
        }
        long long temp = x;
        while(temp>0){
            sum = sum + temp%10;
            temp = temp/10;
        }
        return x*sum;
    }
};