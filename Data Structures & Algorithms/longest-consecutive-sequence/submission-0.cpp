class Solution {
public:

    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int longest = 0;

        for (int x : st) {

            // start of sequence
            if (!st.count(x - 1)) {

                int curr = x;
                int len = 1;

                while (st.count(curr + 1)) {

                    curr++;
                    len++;
                }

                longest = max(longest, len);
            }
        }

        return longest;
    }
};
