/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    string slope(Point a, Point b){
        if(a.x==b.x) return "inf";
        if(a.y==b.y) return "0"; // mistake: must be "0" due to precision 
        stringstream ss;
        ss<<((double)(a.y-b.y)/(double)(a.x-b.x));
        return ss.str();
    }
    int maxPoints(vector<Point>& points) {
        int n = points.size();
        if(n<3) return n;
        int max_pts = 2;
        for(int i=0; i<n-1; i++){
            auto cur = points[i];
            unordered_map<string, int> line_pts;
            int dup_pts = 0;
            for(int j=i+1; j<n; j++){
                auto next = points[j];
                if(cur.x == next.x && cur.y==next.y){
                    dup_pts++;
                }else{
                    string key = slope(cur, next);
                    if(line_pts.find(key)==line_pts.end()){
                        line_pts[key] = 2;
                    }else{
                        line_pts[key]++;
                    }
                }
            }
            int max_pts_in_curline = 1; //initial value should be 1
            for(auto iter = line_pts.begin(); iter!=line_pts.end(); ++iter){
                max_pts_in_curline = max(max_pts_in_curline, iter->second);
            }
            max_pts_in_curline += dup_pts;
            max_pts = max(max_pts, max_pts_in_curline);
        }
        return max_pts;
    }
};
