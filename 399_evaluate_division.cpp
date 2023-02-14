class Solution {

    struct Node {
        string label;
        map<string, double> edges;
    };

public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {

        map<string, Node> graph;

        for (int i = 0; i < equations.size(); ++i) {
            graph[equations[i][0]].label = equations[i][0];
            graph[equations[i][0]].edges[equations[i][1]] = values[i];

            graph[equations[i][1]].label = equations[i][1];
            graph[equations[i][1]].edges[equations[i][0]] = 1.0/values[i];
        }

        vector<double> ans = {};
        for (auto& v: queries) {
            ans.push_back(bfs(v[0], v[1], graph, {}));
        }

        return ans;
    }

    double bfs (const string& start, const string& finish, map<string, Node>& graph, set<string> visited) {

        if (graph.find(start) == graph.end() || graph.find(finish) == graph.end()) {
            return -1.0;
        }

        if (graph[start].edges.find(graph[finish].label) != graph[start].edges.end()) {
            return graph[start].edges[graph[finish].label];
        }

        visited.insert(start);

        double ans = 1.0;
        for (auto& [label, cost]: graph[start].edges) {
            if (visited.find(label) != visited.end()) {
                continue;
            }
            ans *= cost;
            double res = bfs(label, finish, graph, visited);
            if (res != -1.0) {
                return ans*res;
            }
            ans /= cost;
        }

        return -1.0;
    }
}; 
