class Solution {
public:
    bool search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (nums[mid] == target) return true;
        if (nums[low] == nums[mid ] && nums[mid] == nums[high]) {        //ex: 3,1,2,3,3,3,3
            low++;                                                  //nums ka low ,  mid , high all equal
            high--;                                    //in this case try to trim down the space by just 1 on both low and high
            continue;                               //worst case will be O(n/2)
        }
        if (nums[low] <= nums[mid]) {//left is sorted
            if (nums[low] <= target && target <= nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if (nums[mid] <= target && target <= nums[high]) {
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
    }
    return false;
    }
};