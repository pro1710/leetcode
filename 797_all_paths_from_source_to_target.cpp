class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& ans, vector<int>& path, int i){
        path.push_back(i);
        if(i == graph.size()-1) {
            ans.push_back(path);
        } else {
            for(int j = 0; j < graph[i].size(); j++) { 
                dfs(graph, ans, path, graph[i][j]);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> ds;
        vector<vector<int>> ans;
        dfs(graph, ans, ds, 0);
        return ans;
    }
};
