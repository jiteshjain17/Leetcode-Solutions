class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        // O(n), O(1) solution:
        // int curr = 0, total = 0;
        // for(int i = 2; i<nums.size(); i++){
        //     if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2]){
        //         curr++;
        //         total += curr;
        //     }else{
        //         curr = 0;
        //     }
        // }
        // return total;
        
        
        // Dp solution O(n), O(n):
        vector<int> dp(nums.size());
        int count = 0;
        for(int i = 2; i<nums.size(); i++){
            if((nums[i] - nums[i-1]) == (nums[i-1] - nums[i-2])){
                dp[i] = dp[i-1] + 1;
                count += dp[i];
            }
        }
        return count;
    }
};
