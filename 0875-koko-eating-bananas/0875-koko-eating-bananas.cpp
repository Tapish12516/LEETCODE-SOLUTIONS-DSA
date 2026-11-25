class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int maxk = *max_element(piles.begin() , piles.end());
        while(low <= maxk){
            int k = low + (maxk-low)/2;
            long long hours = 0;
            for(int i : piles){
                hours += i/k + (i%k != 0);
            }
            if(hours <= h) maxk = k -1;
            else low = k+1;
        }
        return low;
    }
};