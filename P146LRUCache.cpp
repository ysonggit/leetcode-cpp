class LRUCache{
public:
    struct CacheNode{
        int key, val;
        CacheNode(int k, int v) : key(k), val(v){}
    };
    int size;
    list<CacheNode> cache_list;
    unordered_map<int, list<CacheNode>::iterator> cache_map;
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(cache_map.find(key)==cache_map.end()) return -1;
        auto iter = cache_map[key];
        // move the val to the head of list
        cache_list.splice(cache_list.begin(), cache_list, iter);
        // reset the map value 
        cache_map[key] = cache_list.begin();
        return cache_map[key]->val;
    }
    
    void set(int key, int value) {
        if(cache_map.find(key)==cache_map.end()){
            if(size==cache_map.size()){
                cache_map.erase(cache_list.back().key);
                // remove the tail of cache list
                cache_list.pop_back();
            }
            cache_list.push_front(CacheNode(key, value));
            cache_map[key] = cache_list.begin();
        }else{
            // update map (FIRST) and list
            cache_map[key]->val = value;
            auto iter = cache_map[key];
            cache_list.splice(cache_list.begin(), cache_list, iter);
            cache_map[key] = cache_list.begin();
        }
    }
};
