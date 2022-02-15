class Solution {
public:
    int singleNumber(vector<int>& nums) {

// Using hashing:
//         unordered_map<int,int> mp;
//         for(int i = 0; i<nums.size(); i++){
//             mp[nums[i]]++;
//         }
        
//         for(auto it: mp){
//             if(it.second == 1){
//                 return it.first;
//             }
//         }
//         return -1;
        
        
// Using bit manipulation:
        // Let's say we have an array - [2,1,4,5,2,4,1].
        // What we are doing is essentially this-

        // => 0 ^ 2 ^ 1 ^ 4 ^ 5 ^ 2 ^ 4 ^ 1

        // => 0^ 2^2 ^ 1^1 ^ 4^4 ^5 (Rearranging, taking same numbers together)

        // => 0 ^ 0 ^ 0 ^ 0 ^ 5

        // => 0 ^ 5

        // => 5
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            res ^= nums[i];
        }
        return res;
    }
};
