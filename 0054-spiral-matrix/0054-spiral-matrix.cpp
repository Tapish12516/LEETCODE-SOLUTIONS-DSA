class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0 , bottom = matrix.size()-1;
        int left = 0 , right = matrix[0].size()-1;
        vector<int> vector1;
        while(top <= bottom && left <= right){
            // from left to right
            for(int j = left; j <= right; j++){
                vector1.push_back(matrix[top][j]);
            }
            top++;
            // from top to bottom
            for(int j = top; j <= bottom; j++){
                vector1.push_back(matrix[j][right]);
            }
            right--;
            //from right to left
            if(top <= bottom){                             //neccesary condition to check before entering the inner cicle
                for(int j = right; j >= left; j--){
                    vector1.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            //form bottom to top
            if(left<=right){
                for(int j = bottom; j >= top; j--){
                    vector1.push_back(matrix[j][left]);
                }
                left++;
            }
        }
        return vector1;
    }
};