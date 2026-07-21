class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int fmask = (1 << n) - 1;
        vector<vector<bool>> visited(1 << n, vector<bool>(n, false));
        queue<tuple<int, int, int>> q;
        for(int i = 0; i < n; i++){
            int mask = 1 << i;
            visited[mask][i] = true;
            q.push({mask, i, 0});
        }
        while(!q.empty()){
            auto [mask, node, dist] = q.front();
            q.pop();

            if(mask == fmask) return dist;

            for(int neighbour: graph[node]){
                int next_mask = mask | (1 << neighbour);
                if(!visited[next_mask][neighbour]){
                    visited[next_mask][neighbour] = true;
                    q.push({next_mask, neighbour, dist + 1});
                }
            }
        }
        return -1;
    }
};