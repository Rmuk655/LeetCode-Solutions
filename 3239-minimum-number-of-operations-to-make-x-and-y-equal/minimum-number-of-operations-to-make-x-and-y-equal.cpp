class Solution {
public:
    unordered_map<int,int> memo;
    int target;

    int dfs(int x) {

        if (x <= target)
            return target - x;

        if (memo.count(x))
            return memo[x];

        int ans = x - target; // only decrement

        // divide by 11
        ans = min(ans,
                  x % 11 + 1 + dfs(x / 11));

        ans = min(ans,
                  (11 - x % 11) + 1 + dfs(x / 11 + 1));

        // divide by 5
        ans = min(ans,
                  x % 5 + 1 + dfs(x / 5));

        ans = min(ans,
                  (5 - x % 5) + 1 + dfs(x / 5 + 1));

        return memo[x] = ans;
    }

    int minimumOperationsToMakeEqual(int x, int y) {
        target = y;
        return dfs(x);
    }
};