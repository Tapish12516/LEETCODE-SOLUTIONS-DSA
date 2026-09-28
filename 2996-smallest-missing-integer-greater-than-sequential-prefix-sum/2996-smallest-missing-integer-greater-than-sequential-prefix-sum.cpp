class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        int i;
        for(i = 1 ; i < nums.size() ; i++){
            if(nums[i] == nums[i-1]+1) sum += nums[i];
            else break;
        }
        // if(nums.size() >= 2) sort(nums.begin() , nums.end());                            //nlogn solution
        // for(int j = 0; j < nums.size(); j++) {                  //start from 0 , problems when only single element 
        //     if(nums[j] == sum)
        //         sum++;
        // }

        unordered_set<int> st(nums.begin(), nums.end());            //O(N) TC and SC
        while(st.count(sum)) {
            sum++;
        }
        return sum;
    }
};