class Solution {
public:
    int rec(int idx, int n, vector<int>& costs, vector<int>& dp) {
        if(idx==n) {
            return 0;
        }
        if(dp[idx] != -1) return dp[idx];
        int case1=1e9,case2=1e9,case3=1e9;
        case1 = costs[idx]+1+rec(idx+1,n,costs,dp);
        if(idx+2<=n) {
            case2=costs[idx+1] + 4 + rec(idx+2, n, costs, dp);
        }
        if(idx+3<=n) {
            case3=costs[idx+2] + 9 + rec(idx+3, n, costs, dp);
        }
        return dp[idx]=min({case1, case2, case3});
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1,1e9);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            dp[i]=costs[i]+1+dp[i+1];
            if(i+2<=n){
                dp[i]=min(dp[i],costs[i+1]+4+dp[i+2]);
            }
            if(i+3<=n){
                dp[i]=min(dp[i],costs[i+2]+9+dp[i+3]);
            }
        }
        return dp[0];
    }
};