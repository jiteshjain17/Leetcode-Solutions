class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        int n = nums.size();
        vector<string> v;
        
        if(n == 0) return v;
        
        int start = nums[0];
        for(int i = 0; i<n; i++){
            if(i == n-1 || nums[i+1] != nums[i]+1){
                // if current element not equals start, this means we found a range.
                if(nums[i] != start){
                    v.push_back(to_string(start) + "->" + to_string(nums[i]));
                }else{
                    v.push_back(to_string(start));
                }
                
                // update start unless its the last element
                if(i != n-1){
                    start = nums[i+1];
                }
            }
        }
        return v;
    }
};
