class Solution {
public:
    // from zhiqing_xiao
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > res;
        if(buildings.size()==0) return res;
        multimap<int, int> pos_heights;
        for(auto bldg : buildings){
            pos_heights.emplace(bldg[0], bldg[2]);
            pos_heights.emplace(bldg[1], -1* bldg[2]);
        }
        multiset<int> allheights={0}; //must initialize with 0
        map<int, int> corners;
        for(auto wall : pos_heights){
            int pos = wall.first, height = wall.second;
            if(height>0){
                allheights.insert(height);
            }else{ // the height of the ending wall 
                allheights.erase(allheights.find(-height));
            }
            int cur_height = * allheights.rbegin();
            corners[pos]= cur_height;
        }
        auto equal2nd = [](const pair<int,int>& a, const pair<int,int>&b){ 
            return a.second==b.second;
        }; // do not forget ; for lambda function
        unique_copy(corners.begin(), corners.end(), back_inserter(res), equal2nd);
        return res;
    }
};
