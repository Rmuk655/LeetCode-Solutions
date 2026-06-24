class Solution {
public:
    void dfs(vector<vector<pair<int,int>>> &adj, vector<bool> &visited, int &i, int &ans){
        visited[i] = true;
        for(pair<int, int> x: adj[i]){
            if(!visited[x.first]){
                ans += x.second;
                dfs(adj, visited, x.first, ans);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        int ans = 0;
        for(int i = 0; i < connections.size(); i++){
            int a = connections[i][0], b = connections[i][1];
            adj[a].push_back({b, 1});
            adj[b].push_back({a, 0});
        }
        vector<bool> visited(n, 0);
        int i = 0;
        dfs(adj, visited, i, ans);
        return ans;
    }
};