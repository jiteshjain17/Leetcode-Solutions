class Solution {
public:
    bool isPalindrome(string str, int i, int j){
        int n = str.length();
        if(str.length() == 0 || str.length() == 1) return true;
        while(i < j){
            if(str[i] != str[j]){
                return false;
            }
            i++, j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.length()-1;
        while(i < j){
            if(s[i] != s[j]){
                return (isPalindrome(s,i,j-1) || isPalindrome(s,i+1,j));
            }
            i++, j--;
        }
        return true;
    }
};
