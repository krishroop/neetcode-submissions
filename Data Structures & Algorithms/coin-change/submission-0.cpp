class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {

        vector<int> dp(amount + 1, amount + 1);

        // base case
        dp[0] = 0;

        for (int a = 1; a <= amount; a++) {

            for (int coin : coins) {

                if (a - coin >= 0) {

                    dp[a] =
                        min(dp[a],
                            1 + dp[a - coin]);
                }
            }
        }

        // impossible case
        if (dp[amount] == amount + 1)
            return -1;

        return dp[amount];
    }
};
