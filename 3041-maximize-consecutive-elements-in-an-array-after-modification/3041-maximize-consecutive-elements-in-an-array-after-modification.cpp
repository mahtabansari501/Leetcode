class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int>dp;
        int ans=0;
        for(auto it:nums){
            dp[it+1]=dp[it]+1;
             dp[it]=dp[it-1]+1;
            ans=max({ans,dp[it],dp[it+1]});
        }
        return ans;

    }
};