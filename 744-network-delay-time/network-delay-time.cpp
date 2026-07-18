class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(vector<int> v: times){
            adj[v[0]].push_back({v[1], v[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()){
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]){
                continue;
            }
            for(pair<int, int> p: adj[u]){
                if(p.second + dist[u] < dist[p.first]){
                    dist[p.first] = dist[u] + p.second;
                    pq.push({dist[p.first], p.first});
                }
            }
        }
        int ans = 0;
        for(int i = 1; i < dist.size(); i++){
            ans = max(dist[i], ans);
        }
        if(ans == INT_MAX){
            ans = -1;
        }
        return ans;
    }
};