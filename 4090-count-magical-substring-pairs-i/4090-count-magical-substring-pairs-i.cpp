class Solution {
public:
    long long countMagicalPairs(string s) {
        int n = s.length();
        long long ans = 0;
        for (int j = 0; j < n - 1; ++j) {
            int cntL[27] = {0};
            int distL = 0;
            int freqL[26] = {0};

            for (int i = j; i >= 0; --i) {
                if (freqL[s[i] - 'a'] == 0) {
                    distL++;
                }
                freqL[s[i] - 'a']++;
                cntL[distL]++;
            }
            int cntR[27] = {0};
            int distR = 0;
            int freqR[26] = {0};
            for (int k = j + 1; k < n; ++k) {
                if (freqR[s[k] - 'a'] == 0) {
                    distR++;
                }
                freqR[s[k] - 'a']++;
                cntR[distR]++;
            }
            for (int c = 1; c <= 26; ++c) {
                ans += 1LL * cntL[c] * cntR[c];
            }
        }

        return ans;
    }
};