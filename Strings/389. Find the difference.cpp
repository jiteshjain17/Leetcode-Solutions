class Solution {
public:
    char findTheDifference(string s, string t) {
        
        // O(n), O(1) solutions:
        
        // int x1 = 0, x2 = 0;
        // for(int i : s){
        //     x1 += i;             //int+char=>int+ASCII of char
        // }
        // for(int i : t){
        //     x2 += i;
        // }
        // return (char)(x2-x1);    //converting ASCII to char
        
        
        // int a = 0, b = 0;
        // for(char c : s){
        //     a += c;
        // }
        // for(char c : t){
        //     b += c;
        // }
        // return b-a;
        
        
        // O(n), O(n) using hashmaps:
      
        // unordered_map<char,int> mp;
        // for(int i = 0; i<t.length(); i++){
        //     mp[t[i]]++;
        // }
        // for(int i = 0; i<s.length(); i++){
        //     mp[s[i]]--;
        // }
        // for(auto it: mp){
        //     if(it.second == 1){
        //         return it.first;
        //     }
        // }
        // return '\0';                    // dummy character
        
        
        // Sorting solution O(nlogn):
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        for(int i = 0; i<s.length(); i++){
            if(s[i] != t[i]){
                return t[i];
            }
        }
        return t[s.size()];
    }
};
