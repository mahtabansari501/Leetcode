class Solution {
public:
    void rec(vector<int>& nums, vector<int>& temp,set<vector<int>>& ans, vector<int>& vis) {
        if(temp.size()==nums.size()){
            ans.insert(temp);
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> temp;
        vector<int> vis(nums.size(),0);
        rec(nums,temp,ans,vis);
        vector<vector<int>>ans1;
        for(auto it:ans){
            ans1.push_back(it);
        }
        return ans1;
    }
};