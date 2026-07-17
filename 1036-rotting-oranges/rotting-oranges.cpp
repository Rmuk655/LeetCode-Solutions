class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int f_count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 2){
                    q.push({i, j});
                    visited[i][j] = true;
                }
                else if(grid[i][j] == 1){
                    f_count++;
                }
            }
        }
        if(f_count == 0){
            return 0;
        }
        int ans = 0;
        while(!q.empty()){
            bool cond = false;
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                pair<int, int> p = q.front();
                q.pop();
                if(p.first < m - 1){
                    if(!visited[p.first + 1][p.second] && grid[p.first + 1][p.second] == 1){
                        visited[p.first + 1][p.second] = true;
                        q.push({p.first + 1, p.second});
                        f_count--;
                        cond = true;
                    }
                }
                if(p.second < n - 1){
                    if(!visited[p.first][p.second + 1] && grid[p.first][p.second + 1] == 1){
                        visited[p.first][p.second + 1] = true;
                        q.push({p.first, p.second + 1});
                        f_count--;
                        cond = true;
                    }
                }
                if(p.first > 0){
                    if(!visited[p.first - 1][p.second] && grid[p.first - 1][p.second] == 1){
                        visited[p.first - 1][p.second] = true;
                        q.push({p.first - 1, p.second});
                        f_count--;
                        cond = true;
                    }
                }
                if(p.second > 0){
                    if(!visited[p.first][p.second - 1] && grid[p.first][p.second - 1] == 1){
                        visited[p.first][p.second - 1] = true;
                        q.push({p.first, p.second - 1});
                        f_count--;
                        cond = true;
                    }
                }
            }
            if(cond){
                ans++;
            }
        }
        if(f_count != 0){
            return -1;
        }
        return ans;
    }
};