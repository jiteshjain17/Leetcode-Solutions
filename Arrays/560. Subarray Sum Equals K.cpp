class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
// O(n3) solution:
        // int count = 0;
        // for(int i = 0; i<nums.size(); i++){
        //     for(int j = i+1; j<=nums.size(); j++){
        //         int sum = 0;
        //         for(int x = i; x<j; x++){
        //             sum += nums[x];
        //         }
        //         if(sum == k) count++;
        //     }
        // }
        // return count;
        

// O(n2) solution:
        // int count = 0;
        // for(int i = 0; i<nums.size(); i++){
        //     int sum = 0;
        //     for(int j = i; j<nums.size(); j++){
        //         sum += nums[j];
        //         if(sum == k) count++;
        //     }
        // }
        // return count;
        
        
// O(n), O(n) using hashmap using the idea of prefix sum:      intuition - pepcoding youtube
        unordered_map<int,int> mp;
        int sum = 0, count = 0;
        mp[0] = 1;                           // when sum-k=0, so that we don't miss incrementing count
        
        for(int i = 0; i<nums.size(); i++){
            
            sum += nums[i];
            
            if(mp.find(sum-k) != mp.end()){   // if sum-k has already existed before,we got a subarray
                count += mp[sum-k];
            }
            
            mp[sum]++;
        }
        return count;
    }
};
