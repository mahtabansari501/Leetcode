class Solution {
public:  
    using ll=long long;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        if(costBoth>(cost1+cost2)){
            ll ans=1LL*need1*cost1+1LL*need2*cost2;
            return ans;
        }
        else {
            ll ans=1LL*min(need1,need2)*costBoth;
            if(need1>=need2){
                ans+=(min(costBoth,cost1)*1LL*(need1-need2));
            }
            else {
                ans+=(min(costBoth,cost2)*1LL*(need2-need1));
            }
            return ans;
        }
    }
};