class Solution {
public:

    string longestPalindrome(string s) {

        // preprocess
        string t = "#";

        for (char c : s) {
            t += c;
            t += "#";
        }

        int n = t.size();

        vector<int> p(n, 0);

        int center = 0;
        int right = 0;

        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {

            int mirror = 2 * center - i;

            // reuse previous info
            if (i < right) {
                p[i] = min(right - i, p[mirror]);
            }

            // expand
            int l = i - (p[i] + 1);
            int r = i + (p[i] + 1);

            while (l >= 0 && r < n &&
                   t[l] == t[r]) {

                p[i]++;
                l--;
                r++;
            }

            // update center/right boundary
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            // longest palindrome
            if (p[i] > maxLen) {
                maxLen = p[i];

                start = (i - p[i]) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};