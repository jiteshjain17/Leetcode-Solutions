class Solution {
public:
    bool isSubsequence(string s, string t) {
        
// Recursive approach:
// We traverse both strings from one side to other side (say from rightmost character to leftmost). If we find a matching character, we move ahead in both strings. Otherwise we move ahead only in str2.

        // int m = s.length(), n = t.length();
        // return isSubSeq(s,t,m,n);
        
        
// 2 pointer approach - O(n):
        // int i = 0, j = 0;
        // while(i<s.length() and j<t.length()){
        //     if(s[i] == t[j]){
        //         i++;
        //         j++;
        //     }else{
        //         j++;
        //     }
        // }
        // return i == s.length();
        
        
 // Dynamic programming approach O(mn):
        if(lcs(s,t) == s.length()) return true;
        return false;
    }
    
    bool isSubSeq(string s1, string s2, int m, int n){
        
        if(m == 0) return true;
        if(n == 0) return false;
        
        if(s1[m-1] == s2[n-1]){
            return isSubSeq(s1,s2,m-1,n-1);
        }else{
            return isSubSeq(s1,s2,m,n-1);
        }
    }
    
    int lcs(string s1, string s2){
        int m = s1.length(), n = s2.length();
        int dp[m+1][n+1];
        for(int i = 0; i<m+1; i++){
            for(int j = 0; j<n+1; j++){
                if(i == 0 || j == 0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i<m+1; i++){
            for(int j = 1; j<n+1; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
