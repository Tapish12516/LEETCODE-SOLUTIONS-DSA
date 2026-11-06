class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto &a, auto &b) { return a[1] < b[1]; });
        vector<pair<int,int>> q;
        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());
        vector<int> freq(n + 1, 0);
        vector<int> ans(queries.size());
        int left = 0, right = 0, count = 0;
        for(auto [time, idx] : q) {
            while(right < logs.size() && logs[right][1] <= time) {
                int id = logs[right][0];
                if(freq[id] == 0) count++;
                freq[id]++;
                right++;
            }
            while(left < right && logs[left][1] < time - x) {
                int id = logs[left][0];
                freq[id]--;
                if(freq[id] == 0) count--;
                left++;
            }
            ans[idx] = n - count;
        }
        return ans;
    }
};



// class Solution {
// public:
//     vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
//         vector<int> arr(queries.size());
//         for(int i = 0; i < queries.size(); i++) {
//             int temp = queries[i];
//             unordered_set<int> st;
//             for(int j = 0; j < logs.size(); j++) {         //bruteforce TLE
//                 int t = logs[j][1];
//                 if(t >= temp-x && t <= temp)
//                     st.insert(logs[j][0]);
//             }
//             arr[i] = n - st.size();
//         }
//         return arr;
//     }
// };