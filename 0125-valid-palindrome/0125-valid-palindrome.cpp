class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            while (i < j && !isalnum((unsigned char)s[i])) {
                i++;
            }

            while (i < j && !isalnum((unsigned char)s[j])) {
                j--;
            }

            char ch1 = tolower((unsigned char)s[i]);
            char ch2 = tolower((unsigned char)s[j]);

            if (ch1 != ch2) return false;

            i++;
            j--;
        }

        return true;
    }
};