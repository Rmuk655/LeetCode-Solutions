class Solution {
public:
    bool bfs(int i, vector<vector<int>>& graph, vector<int> &visited){
        visited[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(int x: graph[t]){
                if(visited[x] == -1){
                    visited[x] = 1 - visited[t];
                    q.push(x);
                }
                else if(visited[x] == visited[t]){
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size(), sum = (int) (n * (n - 1)) / 2;
        vector<int> visited(n, -1);;
        for(int i = 0; i < n; i++){
            if(visited[i] == -1 && !bfs(i, graph, visited)){
                return false;
            }
        }
        return true;
    }
};