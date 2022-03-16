class Solution {
public:
    string minRemoveToMakeValid(string s) {
        for(int i = 0; i<s.length(); i++){
            s[i] = tolower(s[i]);
        }
        
        stack<int> st;
        
        if(s.length() == 0) return s;
        
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
               if(!st.empty() and s[st.top()] == '('){
                   st.pop();
               }else{
                   s[i] = '#';
               }
            }
        }
        
        while(!st.empty()){
            s[st.top()] = '#';
            st.pop();
        }
        
        string ans = "";
        for(int i = 0; i<s.length(); i++){
            if(s[i] != '#'){
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};
