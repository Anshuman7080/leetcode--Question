class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dictionarySet(dictionary.begin(), dictionary.end());
        int n = s.length();
        vector<int> dp(n + 1, n);

        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (dictionarySet.find(s.substr(j, i - j)) != dictionarySet.end()) {
                    dp[i] = min(dp[i], dp[j]);
                } else {
                    dp[i] = min(dp[i], dp[j] + i - j);
                }
            }
        }

        return dp[n];
    }
};
