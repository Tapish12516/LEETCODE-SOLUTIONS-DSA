class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;                           //goal will surely present in s+s if not return false
        string temp = s + s;
        if(temp.find(goal) != string::npos)         //optimal soln O(N)
            return true;    
        return false;
    }
};

// class Solution {
// public:
//     void reversestr(string& s, int k) {
//         reverse(s.begin(), s.end());
//         reverse(s.begin(), s.begin() + k);
//         reverse(s.begin() + k, s.end());
//     }
//     bool rotateString(string s, string goal) {
//         if(s.size() != goal.size())
//             return false;
//         for(int i = 0; i < s.size(); i++) {                 //bruteforce solution O(N^2)
//             string temp = s;
//             reversestr(temp, i);
//             if(temp == goal)
//                 return true;
//         }
//         return false;
//     }
// };