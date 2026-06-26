class Solution {
public:

    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(), cmp);

        int remove = 0;

        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] < end) {

                // Overlap
                remove++;
            }
            else {

                // Keep interval
                end = intervals[i][1];
            }
        }

        return remove;
    }
};
