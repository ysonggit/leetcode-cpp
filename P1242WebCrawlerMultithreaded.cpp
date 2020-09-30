class Solution {
private:
    unordered_set<string> visited;
    queue<string> q;
    string hostname;
    HtmlParser *html_Parser;
    mutex mtx;
    
    //extract
    string getHostname(string url)
    {
        int idx = url.find('/', 7); //start find after 7th index (i.e, after "http//:")
        return (idx != string::npos ? url.substr(0, idx) : url);
    }
 
public:    
    void crawlUtil()
    {
        vector<thread*> threadPool;
        
        while (!q.empty())
        {
            string curr_url = q.front();
            q.pop();
            
            
            for (string neighbor : html_Parser->getUrls(curr_url))
            {
                lock_guard<mutex> lg(mtx);
                if (getHostname(neighbor) == hostname && !visited.count(neighbor))
                {
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
            threadPool.push_back(new thread(&Solution::crawlUtil, this));     
        }
        
        for(auto t : threadPool)
            t->join(); 
    }      
    
    //BFS
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        hostname = getHostname(startUrl);        
        html_Parser = &htmlParser;
        
        q.push(startUrl);
        visited.insert(startUrl);
        
        std::thread mainThread(&Solution::crawlUtil, this);
        mainThread.join();
		
        return vector<string>(visited.begin(), visited.end());
    }  
};
