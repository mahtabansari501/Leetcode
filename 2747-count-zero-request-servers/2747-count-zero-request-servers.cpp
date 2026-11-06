class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int m = queries.size();

        vector<pair<int,int>> q;

        for(int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        unordered_map<int,int> mp;

        vector<int> ans(m);

        int l = 0, r = 0;
        int sz = logs.size();

        for(auto [time, idx] : q) {

            int low = time - x;
            int high = time;

            while(r < sz && logs[r][1] <= high) {
                mp[logs[r][0]]++;
                r++;
            }

            while(l < r && logs[l][1] < low) {
                mp[logs[l][0]]--;

                if(mp[logs[l][0]] == 0) {
                    mp.erase(logs[l][0]);
                }

                l++;
            }

            ans[idx] = n - mp.size();
        }

        return ans;
    }
};