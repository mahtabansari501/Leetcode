class Solution {
public:
    void rec(int idx, int n, int target, string &num,
             vector<string>& ans, string s, long long cnt,
             long long s1) {

        if(idx == n) {
            if(target == cnt) ans.push_back(s);
            return;
        }

        for(int i = idx; i < n; i++) {

           if(i > idx && num[idx] == '0') break;

            string curr = num.substr(idx, i-idx+1);
            long long nums = stoll(curr);

            if(idx == 0) {
                rec(i+1,n,target,num,ans,curr,nums,nums);
            }
            else {
                rec(i+1,n,target,num,ans,
                    s+"+"+curr,cnt+nums,nums);
                rec(i+1,n,target,num,ans,
                    s+"-"+curr,cnt-nums,-nums);

                rec(i+1,n,target,num,ans,
                    s+"*"+curr,cnt-s1+s1*nums,s1*nums);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        int n = num.size();

        rec(0,n,target,num,ans,"",0,0);

        return ans;
    }
};