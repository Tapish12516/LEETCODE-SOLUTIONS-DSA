class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mp1[256] = {0};
        int mp2[256] = {0};
        for(int i = 0; i < s.size(); i++) {
            if(mp1[s[i]] == 0 && mp2[t[i]] == 0) {
                mp1[s[i]] = t[i];
                mp2[t[i]] = s[i];
            }
            else if(mp1[s[i]] != t[i] || mp2[t[i]] != s[i]) 
                return false;
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         int n = s.size();
//         for(int i = 0; i < n; i++) {
//             for(int j = i + 1; j < n; j++) {
//                 if(s[i] == s[j] && t[i] != t[j])
//                     return false;                    //bruteforce O(n^2) soln
//                 if(t[i] == t[j] && s[i] != s[j])
//                     return false;
//             }
//         }
//         return true;
//     }
// };