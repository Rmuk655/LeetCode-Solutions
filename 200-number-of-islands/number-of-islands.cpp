class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>> &visited){
        int m = grid.size(), n = grid[i].size();
        visited[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()){
            pair<int, int> p = q.front();
            int a = p.first, b = p.second;
            q.pop();
            if(a < m - 1 && !visited[a + 1][b] && grid[a + 1][b] == '1'){
                visited[a + 1][b] = true;
                q.push({a + 1, b});
            }
            if(b < n - 1 && !visited[a][b + 1] && grid[a][b + 1] == '1'){
                visited[a][b + 1] = true;
                q.push({a, b + 1});
            }
            if(a > 0 && !visited[a - 1][b] && grid[a - 1][b] == '1'){
                visited[a - 1][b] = true;
                q.push({a - 1, b});
            }
            if(b > 0 && !visited[a][b - 1] && grid[a][b - 1] == '1'){
                visited[a][b - 1] = true;
                q.push({a, b - 1});
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    bfs(i, j, grid, visited);
                    ans++;
                }
            }
        } 
        return ans;
    }
};