class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        if(prerequisites.size()==0) {
            for(int i=0;i<numCourses; i++)
                res.push_back(i);
            return res;
        }
        vector<int> incomings(numCourses, 0);
        unordered_map<int, vector<int> > pre_posts;
        for(auto p : prerequisites){
            int post = p.first;
            int pre = p.second;
            incomings[post]++;
            if(pre_posts.find(pre)==pre_posts.end()){
                pre_posts[pre] = vector<int>{};
            }
            pre_posts[pre].push_back(post);
        }
        queue<int> no_inedges;
        for(int i=0; i<numCourses; i++){
            if(incomings[i]==0) no_inedges.push(i);
        }
        while(!no_inedges.empty()){
            int pre = no_inedges.front();
            no_inedges.pop();
            res.push_back(pre);
            for(int post : pre_posts[pre]){
                incomings[post]--;
                if(incomings[post]==0){
                    no_inedges.push(post);
                }
            }
        }
        for(int i: incomings){
            if(i>0) return vector<int>{};
        }
        return res;
    }
};
