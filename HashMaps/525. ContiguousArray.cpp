class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
    // O(n2):
        
        // int ans = 0;
        // int n = nums.size();
        // for(int i = 0; i<n; i++){
        //     int zeros = 0, ones = 0;
        //     for(int j = i; j<n; j++){
        //         zeros += (nums[j] == 0);
        //         ones += (nums[j] == 1);
        //         if(zeros == ones){
        //             ans = max(ans, j-i+1);
        //         }
        //     }
        // }
        // return ans;
        
        
    // O(n) using hashmap:
// https://leetcode.com/problems/contiguous-array/discuss/577279/C%2B%2B-Crystal-Clear-Explanation
        
//         int ans = 0, n = nums.size();
//         unordered_map<int,int> mp;
//         int sum = 0;
        
//         for(int i = 0; i<n; i++){
            
//             sum += (nums[i] == 0) ? -1 : 1;
            
//             auto it = mp.find(sum);
            
//             if(sum == 0){
//                 ans = i+1;
//             }
//             else if(it != mp.end()){
//                 ans = max(ans, i - it->second);
//             }
//             else if(it == mp.end()){
//                 mp.insert({sum,i});
//             }
//         }
//         return ans;
        
        
    // More simpler solution:
        
        int n = nums.size();
        unordered_map<int,int> mp;
        int count = 0, maxlen = 0;
        
        mp[0] = -1;        // for edge case [0,1]
        
        for(int i = 0; i<n; i++){
            count += (nums[i]==0) ? -1 : 1;
            if(mp.find(count) != mp.end()){
                maxlen = max(maxlen, i-mp[count]);
            }else{
                mp[count] = i;
            }
        }
        return maxlen;
    }
};
