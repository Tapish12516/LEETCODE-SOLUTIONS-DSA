class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(nums.size()==1) return nums.back();
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];            //edge cases
        int low = 0 , high = nums.size()-1;
        int mid;
        while(low <= high){
            mid = low + (high - low)/2;
            if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])   //near elements
                return nums[mid];    
            else if ( nums[mid] == nums[mid^1] ) 
                low = mid+1;                                    //if mid = even left half is of no use(all before are in pairs)
            else high = mid-1;
        }
        return -1;
    }
};