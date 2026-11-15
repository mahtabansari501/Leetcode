class Solution {
public:
    long long dfs(int u,vector<vector<int>>&adj,vector<int>&op,vector<int>&score){
        long long sum=score[u];
        long long mn=LLONG_MAX;
        for(auto v:adj[u]){
            long long x=dfs(v,adj,op,score);
            sum+=x;
            mn=min(mn,x);
        }
        if(adj[u].empty())return score[u];
        if(op[u]==1)return sum-mn;
        return sum-min(0LL,mn);
    }
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n=parent.size();
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }
        return dfs(0,adj,op,score);
    }
};