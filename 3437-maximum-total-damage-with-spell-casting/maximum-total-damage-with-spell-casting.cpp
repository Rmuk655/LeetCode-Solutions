class Solution {
public:
    vector<int> val;
    vector<long long> sum;
    vector<long long> dp;

    long long dfs(int i) {
        if (i >= val.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int nxt = upper_bound(val.begin(), val.end(), val[i] + 2) - val.begin();

        long long take = sum[i] + dfs(nxt);
        long long skip = dfs(i + 1);

        return dp[i] = max(take, skip);
    }

    long long maximumTotalDamage(vector<int>& power) {
        int n = power.size();
        if(n == 1){
            return power[0];
        }
        sort(power.begin(), power.end());
        for (int x : power) {
            if (val.empty() || val.back() != x) {
                val.push_back(x);
                sum.push_back(x);
            } else {
                sum.back() += x;
            }
        }
        dp.assign(val.size(), -1);
        return dfs(0);
    }
};