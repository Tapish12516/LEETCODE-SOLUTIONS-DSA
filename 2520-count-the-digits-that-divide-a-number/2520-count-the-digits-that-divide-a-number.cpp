class Solution {
public:
    int countDigits(int num) {
        int dup = num;
        int dig = 0;
        int count = 0;
        while(dup > 0){
            dig = dup%10;
            if(num%dig == 0) count++;
            dup /= 10;
        }
        return count;
    }
};