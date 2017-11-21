class LRUCache {
private:
    int _capacity;
    typedef list<int> Li;
    typedef pair<int, Li::iterator> Pair;
    typedef unordered_map<int, Pair> Cache;
    Li _list;
    Cache cache;
    void refresh(Cache::iterator it) {
        int key = it->first;
        int value = it->second.first;
        auto list_ite = it->second.second;
        _list.erase(list_ite);
        _list.push_front(key);
        it->second.second = _list.begin();
    }
public:
    LRUCache(int capacity): _capacity(capacity) {
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end()) return -1; 
        refresh(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it == cache.end()){
            // check whether full ? 
            if(cache.size() >= _capacity) {
                cache.erase(_list.back());
                _list.pop_back();
            }
            _list.push_front(key);
        }
        else {
            refresh(it);
        }
        cache[key] = make_pair(value, _list.begin());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */