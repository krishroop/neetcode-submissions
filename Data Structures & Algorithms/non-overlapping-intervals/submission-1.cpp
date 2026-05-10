class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        int removeCount = 0;

        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            int start = intervals[i][0];
            int end = intervals[i][1];

            // overlap
            if (start < prevEnd) {

                removeCount++;

                // keep interval with smaller end
                prevEnd = min(prevEnd, end);
            }
            else {

                prevEnd = end;
            }
        }

        return removeCount;
    }
};