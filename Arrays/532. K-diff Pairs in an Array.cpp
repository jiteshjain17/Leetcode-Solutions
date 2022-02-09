class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
// O(n2), O(n) using set:
        
        // set<pair<int,int>> s;
        // for(int i = 0; i<nums.size(); i++){
        //     for(int j = i+1; j<nums.size(); j++){
        //         if(abs(nums[i]-nums[j]) == k and s.find({nums[j],nums[i]}) == s.end()){
        //             s.insert(make_pair(nums[i], nums[j]));
        //         }
        //     }
        // }
        // return s.size();
        
        
// O(n), O(n) using hashmap:
        
//         map<int, int> mp;
//         for(int i = 0; i<nums.size(); i++){
//             mp[nums[i]]++;
//         }
        
//         int count = 0;
//         for(auto it: mp){
//             if(k == 0){                  // Edge case
//                 if(it.second > 1){
//                     count++;
//                 }
//             }else{
//                 if(mp.find(it.first + k) != mp.end()){
//                     count++;
//                 }
//             }
//         }
//         return count;
        
        
// O(nlogn), O(1) using 2 pointers:
        
        sort(nums.begin(), nums.end());
        int count = 0, i = 0, j = 1, n = nums.size();
        
        while(i<n and j<n){
            if(abs(nums[i]-nums[j]) == k){
                count++;
                i++, j++;
                // to avoid repetiotion
                while(j<n and nums[j] == nums[j-1]){
                    j++;
                }
            }else if(abs(nums[i]-nums[j]) < k){
                j++;
            }else if(abs(nums[i]-nums[j]) > k){
                i++;
                if(i == j){
                    j++;
                }
            }
        }
        return count;
    }
};
