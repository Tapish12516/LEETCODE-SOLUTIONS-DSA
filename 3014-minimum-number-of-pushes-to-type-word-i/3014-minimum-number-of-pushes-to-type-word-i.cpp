class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int ans = 0;
        int pushes = 1;
        while (n > 0) {
            int take = min(8, n);
            ans += take * pushes;
            pushes++;
            n -= take;
        }
        return ans;
    }
};
// https://share.google/aimode/5OhVsGRBnQy5KqaTp