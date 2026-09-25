class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;
        for (int j = 0; j < n; j++) {
            if (matrix[0][j] == 0) {
                firstRowZero = true;
                break;
            }
        }
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                firstColZero = true;
                break;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;                       //O(1) approach 
                    matrix[0][j] = 0;                       //first row and column ka use kar liye 
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (firstRowZero) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firstColZero) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};


//         int n = matrix.size();
//         int m = matrix[0].size();
//         for(int i = 0 ; i < n ; i++){
//             for(int j = 0 ; j < n ; j++){
//                 if(matrix[i][j] == 0) {
//                     for(int k = 0 ; k < m; k++){
//                         if(matrix[i][k] != 0) matrix[i][k] = -1;
//                     }
//                     for(int l = 0 ; l < n ; l++){
//                         if(matrix[l][j] != 0) matrix[l][j] = -1;
//                     }                                                        //bruteforce , TC = O( n*m*(n+m) ) , space = O(1)
//                 }                                                            //runtime error on test case 2
//             }
//         }

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (matrix[i][j] == -1)
//                     matrix[i][j] = 0;
//             }
//         }






        // int n = matrix.size();
        // int m = matrix[0].size();
        // vector<int> row(n,0);
        // vector<int> col(m,0);
        // for(int i = 0 ; i < matrix.size() ; i++){
        //     for(int j = 0 ; j < matrix[0].size() ; j++){
        //         if(matrix[i][j] == 0) {
        //             row[i] = 1; col[j] = 1;
        //         }
        //     }
        // }

        // for(int i = 0 ; i < n ; i++){
        //     if(row[i]==1){
        //         for(int j =0;j<m;j++){
        //             matrix[i][j] = 0;                            //TC = O(n*m)
        //         }                                                //better solution but uses O(m+n) space 
        //     }
        // }

        // for(int j = 0; j<m ; j++){
        //     if(col[j] == 1){
        //         for(int i = 0 ; i < n ; i++){
        //             matrix[i][j] = 0;
        //         }
        //     }
        // }





        // int row = 0 ; 
        // for(int i = 0 ; i < matrix.size() ; i++){
        //     int col = 0;
        //     for(int j = 0 ; j < matrix[0].size() ; j++){
        //         if(matrix[i][j] == 0){
        //             row = i ;                                                        //not works 
        //             for(int k = 0 ; k < matrix.size() ; k++){
        //                 matrix[k][j] = 0;
        //             }
        //         }
        //     }
            
        // }