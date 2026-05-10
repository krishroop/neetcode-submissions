class Solution {
public:

    int m, n;

    vector<pair<int,int>> dir = {
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };

    void dfs(vector<vector<int>>& heights,
             int i, int j,
             vector<vector<bool>>& vis) {

        vis[i][j] = true;

        for (auto &d : dir) {

            int ni = i + d.first;
            int nj = j + d.second;

            if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                continue;

            if (vis[ni][nj])
                continue;

            // reverse flow condition
            if (heights[ni][nj] < heights[i][j])
                continue;

            dfs(heights, ni, nj, vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        // Pacific borders
        for (int i = 0; i < m; i++)
            dfs(heights, i, 0, pac);

        for (int j = 0; j < n; j++)
            dfs(heights, 0, j, pac);

        // Atlantic borders
        for (int i = 0; i < m; i++)
            dfs(heights, i, n-1, atl);

        for (int j = 0; j < n; j++)
            dfs(heights, m-1, j, atl);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {

                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};
