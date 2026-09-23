class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long maximum = LLONG_MIN ;
        long long sum = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            sum += nums[i];                                //optimal approach O(n)                              
            if(sum>maximum) maximum = sum;
            if(sum < 0) sum = 0;
        }
        // for(int i = 0 ; i < nums.size() ; i++){
        //     int sum = 0 ;
        //     for(int j = i ; j < nums.size() ; j++){
        //         sum+= nums[j];                             //O(n^2)
        //         if(sum>maximum) maximum = sum;
        //     }
        // }
        return maximum;
    }
};