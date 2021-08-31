#include <iostream>
#include <map>
#include <vector>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> v;
    map<int,bool> chk;
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(chk.count(val) == 0 || !chk[val]){
            v.push_back(val);
            chk[val] = true;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(chk.count(val) > 0 && chk[val]){
            for(int i = 0; i < v.size(); i++){
                if(v[i] == val){
                    v.erase(v.begin()+i);
                    break;
                }
            }
            chk[val] = false;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand()%v.size()];
    }
};
