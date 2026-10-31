class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!isalnum(s[i])) {
                i++;
                continue;
            }
            if (!isalnum(s[j])) {
                j--;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};


// class Solution {
// public:
//     bool isPalindrome(string s) {
//         vector<char> s1;
//         for(char c:s){
//             if(isalnum(c)) s1.push_back(tolower(c));
//         }
//         int i = 0, j = s1.size()-1;
//         while(i<j){
//             if(s1[i] != s1[j]) return false;
//             i++;j--;
//         }
//         return true;
//     }
// };