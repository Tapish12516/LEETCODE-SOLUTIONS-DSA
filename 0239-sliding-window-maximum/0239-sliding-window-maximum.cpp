class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int front = 0 , rear = -1;
        int n = nums.size();
        vector<int> q(n);
        for(int i = 0; i < n ; i++){
            while(front<=rear && q[front]<=i-k ) front++;
            while(front<=rear && nums[q[rear]]<=nums[i]) rear--;
            rear++;
            q[rear] = i;
            if(i>=k-1) ans.push_back(nums[q[front]]);
        }
        return ans;
    }
};