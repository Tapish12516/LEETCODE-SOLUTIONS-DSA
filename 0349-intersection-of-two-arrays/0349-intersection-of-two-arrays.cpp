class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());              //Insert every element from nums1 up to end() into set
        vector<int> ans;
        for(int x : nums2) {
            if(s.count(x)) {
                ans.push_back(x);                                           //optimal approach O(n+m) and O(n)
                s.erase(x);
            }
        }
        return ans;
    }
};