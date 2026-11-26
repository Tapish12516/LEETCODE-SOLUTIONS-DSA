class Solution {
public:
    bool canAliceWin(int n) {
        int i = 10;
        int moves = 0;
        while(n >= i) {
            n -= i;
            i--;
            moves++;
        }
        return moves % 2 == 1;
    }
};