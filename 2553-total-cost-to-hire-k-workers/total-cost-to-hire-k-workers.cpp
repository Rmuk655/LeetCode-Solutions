class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long ans = 0;
        int l = 0, r = n - 1;
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        for(int i = 0; i < k; i++){
            while((int)pq1.size() < candidates && l <= r){
                pq1.push(costs[l++]);
            }
            while((int)pq2.size() < candidates && l <= r){
                pq2.push(costs[r--]);
            }
            if(pq2.empty() || (!pq1.empty() && pq1.top() <= pq2.top())){
                ans += pq1.top();
                pq1.pop();
            }
            else{
                ans += pq2.top();
                pq2.pop();
            }
        }
        return ans;
    }
};