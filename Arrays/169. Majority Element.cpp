class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
// O(n), O(n) using hashmap:
        
//         unordered_map<int,int> mp;
//         for(int i = 0; i<n; i++){
//             mp[nums[i]]++;
//         }
        
//         for(auto it: mp){
//             if(it.second > n/2){
//                 return it.first;
//             }
//         }
//         return -1;
        
        
// O(nlogn) time using sorting
        
        // If the elements are sorted in monotonically increasing (or decreasing) order, the majority           element can be found at index n/2. See the range of indices that are covered by the majority           element. Eg {0,1,2,3,4,5,6} , n=7, so majority element will atleast lie at index 3.
        
        // sort(nums.begin(), nums.end());
        // return nums[n/2];
        
        
        // O(n) solution using Moore's voting algorithm: youtube-striver
        int maj = nums[0];
        int count = 1;
        for(int i = 1; i<n; i++){
            if(count == 0){
                maj = nums[i];
                count++;
            }else if(nums[i] == maj){
                count++;
            }else{
                count--;
            }
        }
        return maj;
    }
};

