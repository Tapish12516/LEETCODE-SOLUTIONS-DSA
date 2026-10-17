class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end(),
             [&](int a, int b) {
                 int sumA = digitSum(a);
                 int sumB = digitSum(b);
                 if (sumA != sumB) return sumA < sumB; return a < b; });
        unordered_map<int, int> position;
        for (int i = 0; i < n; i++) {
            position[sortedNums[i]] = i;
        }
        vector<bool> visited(n, false);
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] || position[nums[i]] == i)
                continue;
            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = position[nums[j]];
                cycleSize++;
            }
            if (cycleSize > 1)
                swaps += cycleSize - 1;
        }
        return swaps;
    }
};