class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int mean=0;
        int n=nums.size();
        int cnt=0;
        sort(nums.begin(),nums.end());
        mean=(nums[n/2]+nums[(n-1)/2])/2;
        for(int i=0;i<n;i++){
            cnt+=abs(mean-nums[i]);
        }
        return cnt;
    }
};