class Solution {
public:
    int calPoints(vector<string>& ops) {
        
        // using vector
//         vector<int> v;
//         int j = -1;
//         for(int i = 0; i<ops.size(); i++){
//             if(ops[i] == "C"){
//                 v.pop_back();
//                 j--;
//             }else if(ops[i] == "D"){
//                 v.push_back(2*v[j]);
//                 j++;
//             }else if(ops[i] == "+"){
//                 v.push_back(v[j] + v[j-1]);
//                 j++;
//             }else{
//                 v.push_back(stoi(ops[i]));
//                 j++;
//             }
//         }
        
//         int sum = 0;
//         for(auto x:v){
//             sum += x;
//         }
//         return sum;
        
        
        // using stack
        stack<int> st;
        for(string s: ops){
            if(s == "C"){
                st.pop();
            }else if(s == "D"){
                st.push(2*st.top());
            }else if(s == "+"){
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.push(val1);
                st.push(val1 + val2);
            }else{
                st.push(stoi(s));
            }
        }
        
        int sum = 0;
        while(!st.empty()){
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};
