class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0 , mid = 0 , high = n-1;
        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[mid] , nums[low]);                    //optimal approach
                low++; mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid] , nums[high]);
                high--;
            }
        }
    }
};


        // int c1 = 0 , c2 = 0 , c3 = 0 ;
        // for(auto it:nums){
        //     if(it == 0) c1++;
        //     else if(it == 1) c2++;
        //     else c3++;
        // }
        // int index = 0 ;                              //bruteforce solution 
        // while(c1--){
        //     nums[index++] = 0;
        // }
        // while(c2--){
        //     nums[index++] = 1;
        // }
        // while(c3--){
        //     nums[index++] = 2;
        // }