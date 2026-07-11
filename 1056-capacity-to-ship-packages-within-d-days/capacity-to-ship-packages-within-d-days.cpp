class Solution {
public:
    bool feasible(int mid, vector<int>& weights, int days){
        int n = 1, temp = 0;
        for(int x: weights){
            if(temp + x > mid){
                n++;
                temp = 0;
            }
            temp += x;
        }
        if(n > days){
            return false;
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0, mini = weights[0];
        for(int x: weights){
            sum += x;
            mini = max(mini, x);
        }
        int l = mini, r = sum, ans = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            if(feasible(mid, weights, days)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};