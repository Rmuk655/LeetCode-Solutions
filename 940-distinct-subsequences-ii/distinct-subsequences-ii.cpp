class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.length();
        long long int MOD = pow(10, 9) + 7;
        vector<long long int> dp(n + 1, 0);
        vector<int> last(26, -1);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            char c = s[i - 1];
            dp[i] = (2 * dp[i - 1]) % MOD;
            if(last[c - 'a'] != - 1){
                dp[i] = (dp[i] - dp[last[c - 'a'] - 1] + MOD) % MOD;
            }
            last[c - 'a'] = i;
        }
        return (int) ((dp[n] - 1 + MOD) % MOD);
    }
};