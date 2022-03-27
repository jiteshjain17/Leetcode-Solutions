class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int m=mat.size();
        int n=mat[0].size();
        
// Brute force: O(m*n + mlogm) time
        vector<int> ans;
        vector<pair<int,int>> v;
        for(int i = 0; i<m; i++){
            int count = 0;
            for(int j = 0; j<n; j++){
                if(mat[i][j] == 1) count++;
            }
            v.push_back({count, i});
        }
        
        sort(v.begin(), v.end());
        for(int i = 0; i<k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
        
// O(mlogm) time:        
//         for(int i = 0; i<m; i++){
//             mat[i].push_back(i);
//         }
        
//         sort(mat.begin(), mat.end());
        
//         vector<int> res(k);
//         for(int i = 0; i<k; i++){
//             res[i] = mat[i][n];
//         }
//         return res;
        
// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/discuss/1201679/C%2B%2B-Python3-No-Heap-No-BS-Simple-Sort-99.20
    }
};
