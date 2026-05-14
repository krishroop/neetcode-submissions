class Solution {
public:

    bool dfs(int node,
             int parent,
             vector<vector<int>>& graph,
             vector<bool>& visited) {

        visited[node] = true;

        for (int nei : graph[node]) {

            // not visited
            if (!visited[nei]) {

                if (!dfs(nei,
                         node,
                         graph,
                         visited))
                    return false;
            }

            // visited but not parent
            else if (nei != parent) {

                return false;
            }
        }

        return true;
    }

    bool validTree(int n,
                   vector<vector<int>>& edges) {

        // tree must have exactly n-1 edges
        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> graph(n);

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);

        // detect cycle
        if (!dfs(0, -1, graph, visited))
            return false;

        // ensure connected
        for (bool v : visited) {

            if (!v)
                return false;
        }

        return true;
    }
};
