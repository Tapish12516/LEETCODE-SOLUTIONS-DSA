class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0; int el;
        for(int i = 0 ; i  <nums.size(); i++){
            if(cnt == 0){
                cnt = 1;
                el = nums[i];
            }
            else if(el == nums[i]) cnt++;
            else cnt--;
        }
        int cnt1 = 0;                                               //optimal approach
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == el) {
                cnt1++;
            }
        }
        if (cnt1 > (nums.size() / 2)) {
            return el;
        }
        return -1;
    }
};

// unordered_map<int , int> mapp;
//         for(int i = 0 ; i < nums.size() ; i++){
//             mapp[nums[i]]++;
//         }
//         int x = nums.size() / 2;
//         for(int i = 0 ; i < nums.size() ; i++){
//             if( mapp[nums[i]] > x ) return nums[i];
//         }
//         return nums[0];