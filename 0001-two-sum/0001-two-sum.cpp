class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> numbers;
        for(int i = 0 ; i < nums.size() ; i++){
            int comp = target - nums[i];
            if( numbers.find(comp) != numbers.end() ){  //find function return index
                return {numbers[comp] , i};
            }
            numbers[nums[i]] = i;
        }
        return {};
    }
};