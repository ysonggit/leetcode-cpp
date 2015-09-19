/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size()<2) return intervals;
        // define lambda comparator for container sort
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){
                return a.start < b.start;
            });
        vector<Interval> res={intervals[0]};
        for(int i=1; i<intervals.size(); i++){
            auto cur = intervals[i];
            if(res.back().end >= cur.start){ //overlap
                res.back().end = max(res.back().end, cur.end);
            }else{
                res.push_back(cur);
            }
        }
        return res;
    }
};
