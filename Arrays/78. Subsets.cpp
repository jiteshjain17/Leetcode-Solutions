class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets = {{}};
        for(int num: nums){
            int n = subsets.size();
            for(int i = 0; i<n; i++){
                subsets.push_back(subsets[i]);
                subsets.back().push_back(num);
            }
        }
        return subsets;
    }
};
