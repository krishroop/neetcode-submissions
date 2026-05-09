class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        for (auto &curr : intervals) {

            // no overlap
            if (ans.empty() || curr[0] > ans.back()[1]) {

                ans.push_back(curr);
            }
            else {

                // merge
                ans.back()[1] =
                    max(ans.back()[1], curr[1]);
            }
        }

        return ans;
    }
};
