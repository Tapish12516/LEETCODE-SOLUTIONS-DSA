class Solution {
public:
    vector<int> findNSE(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while( !st.empty() && arr[st.top()] >= arr[i] ) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSEE(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
  
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);
        long long total = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];  
            long long right = nse[i] - i;   
            long long freq = (left * right) % mod;
            long long val = (freq * arr[i]) % mod;
            total = (total + val) % mod;
        }
        return total;
    }
};


        // int n = arr.size();
        // long long sum = 0;
        // int mod = 1e9 + 7;
        // for (int i = 0; i < n; i++) {               //bruteforce approach  O(N^2)
        //     int mini = arr[i];
        //     for (int j = i; j < n; j++) {
        //         mini = min(mini, arr[j]);
        //         sum = (sum + mini) % mod;
        //     }
        // }
        // return sum;