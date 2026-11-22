class Solution {
public:
    bool checkString(string s) {
        int i =0;
        while(i < s.size()){
            if(s[i] == 'b') break;
            i++;
        }
        for(int j = i; j < s.size(); j++){
            if(s[j] == 'a') return false;
        }
        return true;
    }
};