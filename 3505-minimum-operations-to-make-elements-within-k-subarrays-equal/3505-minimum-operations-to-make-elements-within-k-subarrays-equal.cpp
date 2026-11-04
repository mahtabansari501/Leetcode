class Solution {
private:
    multiset<int> left_set, right_set;
    long long sum_left = 0, sum_right = 0;

    void balance() {
        int left_sz = left_set.size();
        int right_sz = right_set.size();
        int req_left = (left_sz + right_sz + 1) / 2;
        
        while (left_set.size() < req_left) {
            auto it = right_set.begin();
            sum_left += *it;
            sum_right -= *it;
            left_set.insert(*it);
            right_set.erase(it);
        }
        while (left_set.size() > req_left) {
            auto it = prev(left_set.end());
            sum_right += *it;
            sum_left -= *it;
            right_set.insert(*it);
            left_set.erase(it);
        }
    }
    
    void add(int val) {
        if (left_set.empty() || val <= *left_set.rbegin()) {
            left_set.insert(val);
            sum_left += val;
        } else {
            right_set.insert(val);
            sum_right += val;
        }
        balance();
    }
    
    void remove(int val) {
        auto it = left_set.find(val);
        if (it != left_set.end()) {
            sum_left -= val;
            left_set.erase(it);
        } else {
            it = right_set.find(val);
            sum_right -= val;
            right_set.erase(it);
        }
        balance();
    }

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        left_set.clear();
        right_set.clear();
        sum_left = 0;
        sum_right = 0;

        int n = nums.size();
        vector<long long> C(n - x + 1, 0);
        
        for (int i = 0; i < x; ++i) {
            add(nums[i]);
        }
        
        for (int i = 0; i <= n - x; ++i) {
            long long median = *left_set.rbegin();
            
            C[i] = sum_right - (long long)right_set.size() * median 
                 + (long long)left_set.size() * median - sum_left;
            
            if (i + x < n) {
                add(nums[i + x]);
                remove(nums[i]);
            }
        }
        
        const long long INF = 1e18;
        vector<long long> dp(n + 1, 0);
        
        for (int j = 1; j <= k; ++j) {
            vector<long long> next_dp(n + 1, INF);
            for (int i = 1; i <= n; ++i) {
                next_dp[i] = next_dp[i - 1];
                if (i >= x && dp[i - x] != INF) {
                    next_dp[i] = min(next_dp[i], dp[i - x] + C[i - x]);
                }
            }
            dp=next_dp;
        }
        
        return dp[n];
    }
};