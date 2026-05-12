class Solution {
public:

    int countSubstrings(string s) {

        // transform string
        string t = "#";

        for (char c : s) {
            t += c;
            t += "#";
        }

        int n = t.size();

        int count = 0;

        // expand around every center
        for (int i = 0; i < n; i++) {

            int l = i;
            int r = i;

            while (l >= 0 &&
                   r < n &&
                   t[l] == t[r]) {

                // count only real palindromes
                if (t[l] != '#')
                    count++;

                l--;
                r++;
            }
        }

        return count;
    }
};