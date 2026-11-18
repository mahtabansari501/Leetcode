class Solution {
public:
    int minChanges(string s) {
        int cnt1=0,cnt0=0;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt1++;
                if((cnt1+cnt0)%2==0){
                    ans+=min(cnt1,cnt0);
                    cnt0=0;
                    cnt1=0;
                }
            }
            else{
                cnt0++;
                if((cnt1+cnt0)%2==0){
                    ans+=min(cnt1,cnt0);
                    cnt0=0;
                    cnt1=0;
                }
            }
        }
        return ans;
    }
};