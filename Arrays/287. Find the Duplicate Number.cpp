class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size();

// O(n2):
        // for(int i = 0; i<n; i++){
        //     for(int j = i+1; j<n; j++){
        //         if(nums[i] == nums[j]){
        //             return nums[i];
        //         }
        //     }
        // }
        // return -1;
        
// O(nlogn):
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i<n; i++){
        //     if(nums[i] == nums[i+1]){
        //         return nums[i];
        //     }
        // }
        // return -1;
       
        
 // unordered_map, O(n), O(n):       
//         unordered_map<int,int> mp;
//         for(int i = 0; i<n; i++){
//             mp[nums[i]]++;
//         }
        
//         for(auto it: mp){
//             if(it.second > 1){
//                 return it.first;
//             }
//         }
//         return -1;

// unordered set, O(n), O(n):
        // unordered_set<int> s;
        // for(int i = 0; i<n; i++){
        //     if(s.find(nums[i]) != s.end()){
        //         return nums[i];
        //     }
        //     s.insert(nums[i]);
        // }
        // return -1;

// using negative marking: O(n), O(1)
        int ans = -1;
        for(int i = 0; i<n; i++){
            int curr = abs(nums[i]);
            if(nums[curr] < 0){
                ans = curr;
                break;
            }
            nums[curr] *= -1;
        }
        
        for(auto num: nums){
            num = abs(num);
        }
        return ans;
    }
};
