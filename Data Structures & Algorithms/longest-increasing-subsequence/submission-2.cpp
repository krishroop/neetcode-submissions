class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {

        vector<int> lis;

        for (int num : nums) {

            auto it =
                lower_bound(lis.begin(),
                            lis.end(),
                            num);

            // extend LIS
            if (it == lis.end()) {

                lis.push_back(num);
            }

            // replace existing tail
            else {

                *it = num;
            }
        }

        return lis.size();
    }
};