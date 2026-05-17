class Solution {
public:

    string minWindow(string s, string t) {

        unordered_map<char,int> need;
        unordered_map<char,int> window;

        // required frequencies
        for (char c : t) {

            need[c]++;
        }

        int have = 0;
        int needCount = need.size();

        int left = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char c = s[right];

            // expand window
            window[c]++;

            // matched required frequency
            if (need.count(c) &&
                window[c] == need[c]) {

                have++;
            }

            // valid window
            while (have == needCount) {

                // update minimum window
                int len = right - left + 1;

                if (len < minLen) {

                    minLen = len;
                    start = left;
                }

                // shrink from left
                char removeChar = s[left];

                window[removeChar]--;

                // window became invalid
                if (need.count(removeChar) &&
                    window[removeChar] < need[removeChar]) {

                    have--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};
