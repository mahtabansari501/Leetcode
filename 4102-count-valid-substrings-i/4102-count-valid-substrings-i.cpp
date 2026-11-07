class Solution {
public:
    long long countValidSubstrings(string s) {
        int n=s.size();
        int cnt=0;
        vector<int>a;
        for(int i=0;i<n-2;i++){
            if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c'){
                a.push_back(i+2);
            }
        }
        a.push_back(n);
        long long ans=(1LL*a[0]*(a[0]+1))/2;
        for(int i=1;i<a.size();i++){
            long long  nums=a[i]-a[i-1]+1;
            ans+=((nums*(nums+1))/2);
        }
        return ans-(a.size()-1);
    }
};