class Solution {
public:
    int bfs(int i, int j, vector<vector<int>>& grid){
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[i][j] = false;
        queue<pair<int, int>> q;
        q.push({i, j});
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            if(p.first <m-1 && !visited[p.first + 1][p.second]&&grid[p.first + 1][p.second] == 1){
                visited[p.first + 1][p.second] = true;
                q.push({p.first + 1, p.second});
                ans++;
            }
            if(p.second <n-1 && !visited[p.first][p.second + 1]&&grid[p.first][p.second + 1] == 1){
                visited[p.first][p.second + 1] = true;
                q.push({p.first, p.second + 1});
                ans++;
            }
            if(p.first > 0 && !visited[p.first - 1][p.second] && grid[p.first - 1][p.second] == 1){
                visited[p.first - 1][p.second] = true;
                q.push({p.first - 1, p.second});
                ans++;
            }
            if(p.second >0 && !visited[p.first][p.second - 1] && grid[p.first][p.second - 1] == 1){
                visited[p.first][p.second - 1] = true;
                q.push({p.first, p.second - 1});
                ans++;
            }
        }
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0, x = 0;
        int m = grid.size(), n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    x++;
                    ans = max(ans, bfs(i, j, grid));
                }
            }
        }
        if(ans == 0 && x > 0){
            ans = 1;
        }
        return ans;
    }
};