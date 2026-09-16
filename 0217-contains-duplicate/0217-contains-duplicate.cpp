class Solution {
public:
    bool containsDuplicate(vector<int>& nums){
        unordered_set<int> set;
        for(int i =0 ; i<nums.size() ; i++){
            if(set.find(nums[i]) != set.end()) return true;         //same TC and SC but a sligthlt efficient approach
            set.insert(nums[i]);
        }
        return false;
    }
};


// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         for(int num : nums){
//             mp[num]++;                                              // TC and SC = O(N)
//             if(mp[num] > 1)                                         // build full map and then traverses again 
//                 return true;
//         }
//         return false;
//     }
// };