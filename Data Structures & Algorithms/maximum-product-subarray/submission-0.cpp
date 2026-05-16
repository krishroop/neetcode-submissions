class Solution {
public:

    int maxProduct(vector<int>& nums) {

        int currMax = nums[0];
        int currMin = nums[0];

        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            int num = nums[i];

            // save because currMax changes first
            int tempMax = currMax;

            currMax =
                max({
                    num,
                    num * currMax,
                    num * currMin
                });

            currMin =
                min({
                    num,
                    num * tempMax,
                    num * currMin
                });

            ans = max(ans, currMax);
        }

        return ans;
    }
};
