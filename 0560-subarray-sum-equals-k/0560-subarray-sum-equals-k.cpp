class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long, long long> prefixCount;
        prefixCount[0] = 1;
        long long prefixSum = 0;
        long long count = 0;
        for (int value : nums) {
            prefixSum += value;                                         //Optimal Solution O(N) and O(N), TC and SC

            long long neededSum = prefixSum - k;
            if (prefixCount.find(neededSum) != prefixCount.end())
                count += prefixCount[neededSum];
            prefixCount[prefixSum]++;
        }
        return count;
    }
};


        // int n = nums.size();
        // if (n == 0)
        //     return 0;
        // long long count = 0;
        // for (int start = 0; start < n; start++) {
        //     for (int end = start; end < n; end++) {
        //         long long currentSum = 0;
        //         for (int index = start; index <= end; index++) {             //O(N^3) solution
        //             currentSum += nums[index];
        //         }
        //         if (currentSum == k)
        //             count++;
        //     }
        // }
        // return count;