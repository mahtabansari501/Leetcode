class Solution {
public:
    void rec(vector<int>& nums, vector<int>& temp,vector<vector<int>>& ans, vector<int>& vis) {
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=1;
                temp.push_back(nums[i]);
                rec(nums,temp,ans,vis);
                temp.pop_back();
                vis[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> vis(nums.size(),0);
        rec(nums,temp,ans,vis);
        return ans;
    }
};