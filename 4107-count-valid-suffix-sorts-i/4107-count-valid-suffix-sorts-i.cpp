class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        map<int,int>mp1,mp2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp1[nums[i]]++;
            mp2[target[i]]++;
        }
        if(mp1.size()!=mp2.size()){
            return 0;
        }
        for(auto it:mp1){
            if(mp2.find(it.first)==mp2.end()||mp2[it.first]!=it.second){
                return 0;
            }
        }
        vector<int>a(n,0);
        for(int i=n-1;i>0;i--){
            if(target[i]<=target[i-1]){
                a[i-1]=1;
            }
            else break;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                ans++;
            }
            else if(i==n-1&&nums[i]==target[i]){
                ans++;
            }
            if(nums[i]!=target[i]){
                break;
            }
        }
        return ans;
    }
};