class LRUCache {
    list<pair<int,int>> list_arr; // for key and value pair.
    unordered_map<int,list<pair<int,int>> ::iterator> m; // for key and it's location
    int max_cap = 0;
public:
    
    LRUCache(int capacity) {
        max_cap = capacity;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            auto it = m[key]; // find location of key.
            list_arr.splice(list_arr.begin(),list_arr,it);// move key to front of list.
            return list_arr.front().second;
        }
    return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            list_arr.erase(m[key]);
        }
        else if(list_arr.size()==max_cap)
        {
            m.erase(list_arr.back().first);
            list_arr.pop_back();
        }
    list_arr.push_front({key,value});
    m[key] = list_arr.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */