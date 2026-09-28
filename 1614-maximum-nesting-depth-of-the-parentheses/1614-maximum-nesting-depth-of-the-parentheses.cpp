class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int ans = 0;
        for(char c : s) {
            if(c == '(') {
                depth++;
                ans = max(ans, depth);      //no need of stack , can use simple death pointer
            }
            else if(c == ')')  depth--;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int maxDepth(string s) {
//         stack<char> st;
//         int ans = 0;
//         for(char c : s) {
//             if(c == '(') {
//                 st.push(c);
//                 ans = max(ans, (int)st.size());     //ans is keep tracking the maximum no. of ( in stack 
//             }
//             else if(c == ')')  st.pop();
//         }
//         return ans;
//     }
// };