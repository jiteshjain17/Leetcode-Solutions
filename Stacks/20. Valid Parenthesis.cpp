class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else if(s[i] == ')' and st.size() > 0 and st.top() == '('){
                st.pop();
            }else if(s[i] == '}' and st.size() > 0 and st.top() == '{'){
                st.pop();
            }else if(s[i] == ']' and st.size() > 0 and st.top() == '['){
                st.pop();
            }else{
                return false;
            }
        }
        return st.empty();
    }
};
