class Solution {
public:
    // bool is(string s, vector<string>& wordDict){
    //     for(string x: wordDict){
    //         if(x == s){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    // bool canbreak(int st, int end, string s, vector<string>& wordDict){
    //     string x = "";
    //     for(int i = st; i <= end; i++){
    //         x += s[i];
    //     }
    //     if(is(x, wordDict)){
    //         return true;
    //     }
    //     string temp = "";
    //     bool ans = false;
    //     for(int i = st; i <= end; i++){
    //         temp += s[i];
    //         if(is(temp, wordDict)){
    //             ans |= canbreak(i + 1, end, s, wordDict);
    //         }
    //     }
    //     return ans;
    // }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(string w: wordDict){
                int l = w.length();
                if(i >= l && dp[i - l] && s.substr(i - l, l) == w){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];

        // string temp = "";
        // for(int i = 0; i < n; i++){
        //     temp += s[i];
        //     if(is(temp, wordDict)){
        //         dp[i] = true;
        //     }
        //     for(int j = 0; j <= i; j++){
        //         string x = "";
        //         for(int k = i + 1; k < n; k++){
        //             x += s[k];
        //         }
        //         if(is(x, wordDict)){
        //             return true;
        //         }
        //     }
        // }
        // return dp[n];
        // return canbreak(0, n - 1, s, wordDict);
    }
};