class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int numOfProvinces = 0;
        vector<int> visited(isConnected.size(), 0);

        for (int i = 0; i < isConnected.size(); ++i) {
            if (!visited[i]) {
                numOfProvinces++;
                dfs(i, visited, isConnected);
            }
            
        }
        return numOfProvinces;

    }

    void dfs(int city, vector<int>& visited, const vector<vector<int>>& isConnected) {
        visited[city] = 1;
        for (int i = 0; i < isConnected.size(); ++i) {
            if (isConnected[city][i] && !visited[i]) {
                dfs(i, visited, isConnected);
            }
        }
    }
};

Console
