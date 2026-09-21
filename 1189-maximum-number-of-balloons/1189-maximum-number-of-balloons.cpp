class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char , int> mapp;                    
        string s = "balloon";
        for( int i = 0 ; i < 7 ; i++){
            mapp[s[i]] = 0 ;
        }
        for(char ch : text) {
            mapp[ch]++;
        }
        int arr[5];
        arr[0] = mapp['b'];
        arr[1] = mapp['a'];
        arr[2] = mapp['l'] / 2;
        arr[3] = mapp['o'] / 2;
        arr[4] = mapp['n'];
        return *min_element(arr, arr + 5);
    }
};