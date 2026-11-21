
class Solution {
public:
    int k=26;
    vector<int>a=vector<int>(26,-1);
    vector<int>par;

    void dfs(int node,int parents,vector<vector<int>>&adj,string &s){
        if(a[s[node]-'a']==-1){
            par[node]=parents;
            a[s[node]-'a']=node;

            for(auto child:adj[node]){
                dfs(child,node,adj,s);
            }

            a[s[node]-'a']=-1;
        }
        else{
            int old=a[s[node]-'a'];
            par[node]=old;
            a[s[node]-'a']=node;

            for(auto child:adj[node]){
                dfs(child,node,adj,s);
            }

            a[s[node]-'a']=old;
        }
    }

    void dfs2(int node,vector<vector<int>>&adj2,vector<int>&sz){
        sz[node]=1;

        for(auto child:adj2[node]){
            dfs2(child,adj2,sz);
            sz[node]+=sz[child];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        par.resize(n);

        vector<int>sz(n,1);
        vector<vector<int>>adj(n);

        for(int i=1;i<n;i++){
            adj[parent[i]].push_back(i);
        }

        dfs(0,-1,adj,s);

        vector<vector<int>>adj2(n);

        for(int i=1;i<n;i++){
            adj2[par[i]].push_back(i);
        }

        dfs2(0,adj2,sz);

        return sz;
    }
};
