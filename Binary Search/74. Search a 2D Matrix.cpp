class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // for(int i = 0; i<m; i++){
        //     for(int j = 0; j<n; j++){
        //         if(matrix[i][j] == target) return true;
        //     }
        // }
        // return false;
        
        
        // int i = 0, j = matrix[0].size()-1;
        // while(i < m and j >= 0){
        //     if(matrix[i][j] == target){
        //         return true;
        //     }
        //     if(matrix[i][j] < target){
        //         i++;
        //     }else{
        //         j--;
        //     }
        // }
        // return false;
        
        
        int l = 0, r = m*n - 1;
        while(l != r){
            int mid = (l + r)/2;
            if(matrix[mid/n][mid%n] < target){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return matrix[r/n][r%n] == target;
    }
};
