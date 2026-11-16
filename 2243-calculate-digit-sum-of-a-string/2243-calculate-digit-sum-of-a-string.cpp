class Solution {
public:
    string digitSum(string s, int k) {
        // if (k == 1) return s;            //if constraints were given with k >= 1
        while (s.length() > k) {
            string ans = "";
            for (int i = 0; i < s.length(); i += k) {
                int sum = 0;
                for (int j = i; j < min((int)s.length(), i + k); j++) {
                    sum += s[j] - '0';
                }
                ans += to_string(sum);
            }
            s = ans;
        }
        return s;
    }
};