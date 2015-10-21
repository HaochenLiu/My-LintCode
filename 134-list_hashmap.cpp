/*
134. LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
Have you met this question in a real interview?
Example
*/

#include<list>

struct CacheNode{
    int key;
    int value;
    CacheNode(int k , int v) : key(k), value(v){}
};

class LRUCache{
public:
    // @param capacity, an integer
    LRUCache(int capacity) {
        // write your code here
        size = capacity;
    }
    
    // @return an integer
    int get(int key) {
        // write your code here
        if(cacheMap.find(key) != cacheMap.end()) {
            auto it = cacheMap[key];
            cacheList.splice(cacheList.begin(), cacheList , it);
            cacheMap[key] = cacheList.begin();
            return cacheList.begin()->value;
        } else {
            return -1;
        }
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // write your code here
        if (cacheMap.find(key) != cacheMap.end()) {
            auto it = cacheMap[key];
            it->value = value;
            cacheList.splice(cacheList.begin(), cacheList , it);
        } else {
            if(cacheList.size() == size) {
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(CacheNode(key, value));
            cacheMap[key] = cacheList.begin();
        }
    }

private:
    int size;
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
};
