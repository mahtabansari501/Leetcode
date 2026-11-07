class Solution {
public:
    using ll=long long;
    long long countValidSubstrings(string s) {
        ll ans=0;
        ll f1=-1,f2=-1,f3=-1;
        int n=s.size();
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'){
                f1=i;
            }
            else if(s[i]=='b'){
                f2=max(f2,f1);
            }
            else if(s[i]=='c'){
                f3=max(f3,f2);
            }
            ans+=(i-f3);
        }
        return ans;
    }
};