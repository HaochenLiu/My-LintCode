/*
134. LRU Cache

Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
Have you met this question in a real interview?
Example
*/

#include<list>

class CacheNode{
public:
    int key;
    int val;

    CacheNode(int k, int v) {
        key = k;
        val = v;
    }
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
        if(CacheMap.find(key) == CacheMap.end()) return -1;
        list<CacheNode>::iterator it = CacheMap[key];
        CacheList.splice(CacheList.begin(), CacheList, it);
        return it->val;
    }

    // @param key, an integer
    // @param value, an integer
    // @return nothing
    void set(int key, int value) {
        // write your code here
        if(CacheMap.find(key) == CacheMap.end()) {
            if(CacheList.size() == size) {
                CacheMap.erase(CacheList.back().key);
                CacheList.pop_back();
            }
            CacheList.push_front(CacheNode(key, value));
            CacheMap[key] = CacheList.begin();
        } else {
            list<CacheNode>::iterator it = CacheMap[key];
            it->val = value;
            CacheList.splice(CacheList.begin(), CacheList, it);
        }
    }

private:
    int size;
    list<CacheNode> CacheList;
    unordered_map<int, list<CacheNode>::iterator> CacheMap;
};
