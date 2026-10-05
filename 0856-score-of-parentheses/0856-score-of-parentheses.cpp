class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0, depth = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(')  ++depth; 
            else {
                --depth;
                if (s[i - 1] == '(')  score += 1 << depth;
            }
        }
        return score;
    }
};

// class Solution {
//     public int scoreOfParentheses(String S) {
//         Stack<Integer> stack = new Stack<>();
//         stack.push(0);
//         for (char c : S.toCharArray()) {
//             if (c == '(')  stack.push(0);
//             else {
//                 int v = stack.pop();
//                 int w = stack.pop();
//                 stack.push(w + Math.max(2 * v, 1));
//             }
//         }
//         return stack.pop();
//     }
// }