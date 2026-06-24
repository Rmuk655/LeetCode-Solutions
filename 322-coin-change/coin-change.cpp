class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int maxi = coins[0];
        for(int x: coins){
            maxi = max(x, maxi);
        }
        if(amount < maxi){
            maxi = coins[0];
            for(int x: coins){
                if(x <= amount){
                    maxi = max(x, maxi);
                }
            }
        }
        vector<int> dp(amount + 1, INT_MAX - 1);
        dp[0] = 0;
        for(int x: coins){
            if(x <= amount){
                dp[x] = 1;
            }
        }
        for(int i = 1; i <= amount; i++){
            for(int x: coins){
                if(x <= amount && i >= x){
                    dp[i] = min(dp[i], dp[i - x] + 1);
                }
            }
        }
        if(dp[amount] == INT_MAX - 1){
            dp[amount] = -1;
        }
        return dp[amount];
    }
};