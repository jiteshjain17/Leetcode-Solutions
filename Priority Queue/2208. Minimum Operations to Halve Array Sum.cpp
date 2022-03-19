class Solution {
public:
    int halveArray(vector<int>& nums) {
        
        int n = nums.size();
        double sum = 0;
        priority_queue<double> pq;
        for(int i = 0; i<n; i++){
            sum += nums[i];
            pq.push(nums[i]);
        }
        
        int count = 0;
        double req_sum = sum/2;
        while(sum > req_sum){
            double curr_top = pq.top();
            pq.pop();
            curr_top = curr_top/2;
            sum -= curr_top;
            pq.push(curr_top);
            count++;
        }
        return count;
    }
};
