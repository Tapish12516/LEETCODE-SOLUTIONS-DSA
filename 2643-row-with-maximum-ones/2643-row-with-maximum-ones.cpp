class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxCount = -1;
        int ans = 0;
        for(int i = 0; i < mat.size(); i++) {
            int count = 0;
            for(int j = 0; j < mat[i].size(); j++) {
                if(mat[i][j] == 1)  count++;
            }
            if(count > maxCount) {
                maxCount = count;
                ans = i;
            }
        }
        return {ans, maxCount};
    }
};


        // if(mat.empty() || mat[0].empty()) return -1;
        // vector<int> rows;
        // for(int i = 0; i < mat.size(); i++){
        //     int count = 0;
        //     for(int j =0; j < mat[0].size(); j++){
        //         if(mat[i][j] == 1) count++;
        //     }
        //     rows.push_back(count);
        // }
        // int maxcount = *max_element(rows.begin() , rows.end());
        // if(maxcount == 0) return -1;
        // for(int i =0; i < rows.size() ; i++){
        //     if(rows[i] == maxcount) return i;
        // }
        // return -1;