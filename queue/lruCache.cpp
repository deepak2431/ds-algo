struct Cache {
    
    int key_, value_;
    Cache(int key = 0, int value = 0) {
        key_ = key;
        value_ = value;
    }
};

class LRUCache {
public:
    
    list<Cache> cache;
    unordered_map<int, list<Cache>::iterator>posMap;
    int frameSize;
    LRUCache(int capacity) {
        frameSize = capacity;
    }
    
    int get(int key) {
        
        if(posMap.find(key) == posMap.end())
            return -1;
        
        auto it = posMap[key];
        cache.push_front(*it);
        cache.erase(it);
        posMap[key] = cache.begin();
        return posMap[key]->value_;  
    }
    
    void put(int key, int value) {
        
        if(posMap.find(key) == posMap.end()) {
            
            cache.push_front(Cache(key, value));
            posMap[key] = cache.begin();
            if(cache.size() > frameSize) {
                
                auto last = cache.back();
                posMap.erase(last.key_);
                cache.pop_back();
            }  
        }
        else {
            auto it = posMap[key];
            it->value_ = value;
            cache.push_front(*it);
            cache.erase(it);
            posMap[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */