class Solution {
public:
    void reversestr(string& s, int k) {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + k);
        reverse(s.begin() + k, s.end());
    }
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        for(int i = 0; i < s.size(); i++) {
            string temp = s;
            reversestr(temp, i);
            if(temp == goal)
                return true;
        }
        return false;
    }
};