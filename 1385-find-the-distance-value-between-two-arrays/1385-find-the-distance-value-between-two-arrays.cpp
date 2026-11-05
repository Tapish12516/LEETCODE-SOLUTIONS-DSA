class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        bool istrue = true;
        int count = 0;
        for(int i = 0; i<arr1.size(); i++){
            istrue = true;                                                          //O(n*m)
            for(int j = 0; j<arr2.size(); j++){
                if(abs(arr2[j] - arr1[i]) <= d) {
                    istrue = false;
                    break;
                }
            }
            if(istrue) count++;
        }
        return count;
    }
};


// class Solution {
// public:
//     int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
//         sort(arr2.begin(), arr2.end());
//         int count = 0;
//         for (int x : arr1) {
//             auto it = lower_bound(arr2.begin(), arr2.end(), x);
//             bool valid = true;
//             if (it != arr2.end() && abs(*it - x) <= d)                           //optimal soln nlogn
//                 valid = false;
//             if (it != arr2.begin() && abs(*prev(it) - x) <= d)
//                 valid = false;
//             if (valid) count++;
//         }
//         return count;
//     }
// };