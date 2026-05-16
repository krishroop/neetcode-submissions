class Solution {
public:

    vector<int> parent;
    vector<int> rankv;

    int find(int x) {

        // leader found
        if (parent[x] == x)
            return x;

        // path compression
        return parent[x] =
            find(parent[x]);
    }

    bool unite(int x, int y) {

        int px = find(x);
        int py = find(y);

        // already connected
        if (px == py)
            return false;

        // union by rank
        if (rankv[px] > rankv[py]) {

            parent[py] = px;
        }
        else if (rankv[px] < rankv[py]) {

            parent[px] = py;
        }
        else {

            parent[py] = px;

            rankv[px]++;
        }

        return true;
    }

    int countComponents(int n,
                        vector<vector<int>>& edges) {

        parent.resize(n);
        rankv.resize(n, 0);

        // initially every node
        // is its own parent
        for (int i = 0; i < n; i++) {

            parent[i] = i;
        }

        int components = n;

        for (auto &e : edges) {

            int u = e[0];
            int v = e[1];

            // merged successfully
            if (unite(u, v)) {

                components--;
            }
        }

        return components;
    }
};