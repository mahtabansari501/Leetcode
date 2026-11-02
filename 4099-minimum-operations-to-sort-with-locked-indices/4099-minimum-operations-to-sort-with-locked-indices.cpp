class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        vector<int>a=nums;
        int n = nums.size();
        int req_unlocks=0;
        int max_val = 0;
        for(int i=0;i<n;i++){
            max_val=max(max_val,nums[i]);
            if(locked[i]==1) {
                if (nums[i]!=i+1||max_val>i+1){
                    req_unlocks++;
                }
            }
        }
        if(req_unlocks>k){
            return -1;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]){
                    cnt++;
                }
            }
        }
        return req_unlocks+cnt;
    }
};