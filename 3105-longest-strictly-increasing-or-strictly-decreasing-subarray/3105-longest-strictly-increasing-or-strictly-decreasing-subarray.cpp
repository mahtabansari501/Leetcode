class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi=1;
        int cnt=1;
        int f=-1;
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                if(f==0)cnt++;
                else {
                    maxi=max(cnt,maxi);
                    f=0;
                    cnt=2;
                }
            }
            else if(nums[i]<nums[i-1]){
                if(f==1)cnt++;
                else {
                    maxi=max(cnt,maxi);
                    f=1;
                    cnt=2;
                }
            }
            else {
                f=-1;
                maxi=max(maxi,cnt);
                cnt=1;
            }
        }
         maxi=max(maxi,cnt);
         return maxi;
    }
};