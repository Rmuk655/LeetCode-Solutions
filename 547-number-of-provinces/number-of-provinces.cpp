class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool> &visited, int i){
        visited[i] = true;
        for(int j = 0; j < isConnected[i].size(); j++){
            if(!visited[j] && isConnected[i][j]){
                dfs(isConnected, visited, j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(isConnected, visited, i);
                ans++;
            }
        }
        return ans;
    }
};