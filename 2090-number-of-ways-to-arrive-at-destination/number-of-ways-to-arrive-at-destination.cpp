class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const long long int MOD = pow(10, 9) + 7;
        vector<vector<pair<int, long long int>>> adj(n);
        for(vector<int> v: roads){
            adj[v[0]].push_back({v[1], (long long) v[2]});
            adj[v[1]].push_back({v[0], (long long) v[2]});
        }
        priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<>> pq;
        vector<long long int> dist(n, LLONG_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while(!pq.empty()){
            pair<long long int, int> p = pq.top();
            pq.pop();
            if(p.first > dist[p.second]){
                continue;
            }
            for(pair<int, long long int> pa: adj[p.second]){
                if(pa.second + dist[p.second] < dist[pa.first]){
                    dist[pa.first] = dist[p.second] + pa.second;
                    ways[pa.first] = ways[p.second] % MOD;
                    pq.push({dist[pa.first], pa.first});
                }
                else if(pa.second + dist[p.second] == dist[pa.first]){
                    ways[pa.first] = (ways[p.second] + ways[pa.first]) % MOD;
                }
            }
        }
        int ans = ways[n - 1];
        return ans;
    }
};