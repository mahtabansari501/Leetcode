class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>>ans;
        string t1="",t2="";
        int idx=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                t1+=s1[i];
                t2+=s2[i];
            }
            else{
                if(t1.size()>0){
                ans.push_back({t1,t2});
                }
                t1="";
                t2="";
            }
        }
        if(t1.size()>0){
            ans.push_back({t1,t2});
        }
        return ans;
    }
};