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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        if(n==0) return vector<Interval>{newInterval};
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end(), [](Interval& a, Interval& b){
           return a.start < b.start; 
        });
        vector<Interval> res {intervals.front()};
        for(int i=1; i<intervals.size(); i++){
            auto cur = intervals[i];
            if(res.back().end >= cur.start){
                res.back().end = max(res.back().end, cur.end);
            }else{
                res.push_back(cur);
            }
        }
        return res;
    }
};
