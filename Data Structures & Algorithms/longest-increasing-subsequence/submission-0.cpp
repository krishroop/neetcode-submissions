class Solution {
public:

    int solve(int i,
              int prev,
              vector<int>& nums,
              vector<vector<int>>& dp) {

        // reached end
        if (i == nums.size())
            return 0;

        // prev+1 because prev can be -1
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        // option 1: skip current
        int skip =
            solve(i + 1,
                  prev,
                  nums,
                  dp);

        // option 2: take current
        int take = 0;

        if (prev == -1 ||
            nums[i] > nums[prev]) {

            take =
                1 +
                solve(i + 1,
                      i,
                      nums,
                      dp);
        }

        return dp[i][prev + 1] =
            max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<vector<int>> dp(
            n,
            vector<int>(n + 1, -1)
        );

        return solve(0, -1, nums, dp);
    }
};
