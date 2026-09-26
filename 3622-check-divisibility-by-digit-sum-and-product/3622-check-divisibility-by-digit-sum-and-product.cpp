class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int sum = 0;
        int digsum = 0;
        int digpro = 1;
        while(temp>0){
            int dig = temp%10;
            digsum += dig;
            digpro *= dig;
            temp /= 10;
        }
        return !(n%(digsum + digpro));
    }
};