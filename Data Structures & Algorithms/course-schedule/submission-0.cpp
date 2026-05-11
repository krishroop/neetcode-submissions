class Solution {
public:

    bool dfs(int node,
             vector<vector<int>>& graph,
             vector<int>& state) {

        // currently visiting -> cycle
        if (state[node] == 1)
            return false;

        // already processed
        if (state[node] == 2)
            return true;

        state[node] = 1;

        for (int nei : graph[node]) {

            if (!dfs(nei, graph, state))
                return false;
        }

        state[node] = 2;

        return true;
    }

    bool canFinish(int numCourses,
                   vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        for (auto &p : prerequisites) {

            int a = p[0];
            int b = p[1];

            graph[b].push_back(a);
        }

        vector<int> state(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {

            if (!dfs(i, graph, state))
                return false;
        }

        return true;
    }
};
