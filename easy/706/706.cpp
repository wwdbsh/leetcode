#include <iostream>
#include <map>

using namespace std;

class MyHashMap {
    map<int,int> hm;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        this->hm = map<int,int>();
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        this->hm[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return this->hm.count(key) > 0 ? this->hm[key] : -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        this->hm.erase(key);
    }
};