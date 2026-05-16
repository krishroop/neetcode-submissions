class Solution {
public:

    void dfs(int node,
             vector<vector<int>>& graph,
             vector<bool>& visited) {

        visited[node] = true;

        for (int nei : graph[node]) {

            if (!visited[nei]) {

                dfs(nei,
                    graph,
                    visited);
            }
        }
    }

    int countComponents(int n,
                        vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);

        // build adjacency list
        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);

        int components = 0;

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                dfs(i,
                    graph,
                    visited);

                components++;
            }
        }

        return components;
    }
};
