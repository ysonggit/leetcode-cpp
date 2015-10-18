class Solution {
public:
    void updateGraph(string wd1, string wd2, 
        unordered_map<char, unordered_set<char> > & graph,
        unordered_map<char, int> & incomings)
    {
        int m = wd1.length(), n = wd2.length();
        char from, to;
        bool found = false;
        for(int i=0; i<min(m, n); i++){
            if(wd1[i] == wd2[i]) continue;
            from = wd1[i];
            to = wd2[i];
            found = true;
            break;
        }
        if(!found){
            if(m==n) return; // "z" "z"
            else{
                from = (m<n) ? wd1[m-1] : wd2[n-1];
                to = (m<n) ? wd2[n-1] : wd1[m-1];
            }
        }
        if(graph.find(from)== graph.end()){
            graph[from] = unordered_set<char>{};
        }
        if(graph[from].find(to) == graph[from].end()) graph[from].insert(to);
        incomings[to]++;
        //cout<<"["<<from<<"] ---> ["<<to<<"]"<<endl;
    }
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char> > graph;
        unordered_map<char, int> incomings;
        if(words.size()==0) return "";
        for(auto wd : words){
            for(char c : wd){ // must count every character
                if(incomings.find(c)==incomings.end()) incomings[c]=0;
            }
        }
        // construct a graph, represented by an adjacent list
        for(int i=1; i<words.size(); i++){
            updateGraph(words[i-1], words[i], graph, incomings);
        }
        deque<char> no_incoming;
        for(auto it = incomings.begin(); it!=incomings.end(); ++it){
            if(it->second==0) no_incoming.push_back(it->first);
        }
        string order;
        while(!no_incoming.empty()){
            char cur = no_incoming.front();           
            no_incoming.pop_front();
            order.push_back(cur);
            for(auto it = graph[cur].begin(); it!= graph[cur].end(); ++it){
                char nex = *it;
                incomings[nex]--;
                if(incomings[nex]==0){
                    no_incoming.push_back(nex);
                }
            }
        }
        for(auto it=incomings.begin(); it!=incomings.end(); ++it){
            if(it->second !=0) return "";
        }
        return order;
    }
};
