class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

    int m = matrix.size();
    int n = matrix[0].size();

    vector<bool> rows(m, false);
    vector<bool> cols(n, false);

    // mark rows/cols
    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            if (matrix[i][j] == 0) {
                rows[i] = true;
                cols[j] = true;
            }
        }
    }

    // set zeros
    for (int i = 0; i < m; i++) {

        for (int j = 0; j < n; j++) {

            if (rows[i] || cols[j]) {
                matrix[i][j] = 0;
            }
        }
    }
}
};
