class Solution {
public:
    using ll=long long;
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        vector<pair<pair<int,int>,int>>st;
        int n=types.size();
        for(int i=0;i<n;i++){
            if(!st.empty()&&st.back().first.first==types[i]&&st.back().first.second==colors[i]){
                st.back().second++;
            }
            else {
                st.push_back({{types[i],colors[i]},1});
            }
            if(st.back().second==groupSize[types[i]]){
                st.pop_back();
            }
        }
        return st.empty();
    }
};