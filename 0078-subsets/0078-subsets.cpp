class Solution {
public:
    void rec(int idx,int n,vector<int>&nums,vector<int>&a,vector<vector<int>>&ans){
        if(idx==n){
            ans.push_back(a);
            return ;
        }
        a.push_back(nums[idx]);
        rec(idx+1,n,nums,a,ans);
        a.pop_back();
        rec(idx+1,n,nums,a,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>a;
        int n=nums.size();
        rec(0,n,nums,a,ans);
        return ans;
    }
};