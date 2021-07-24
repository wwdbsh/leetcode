#include <iostream>
#include <vector>

using namespace std;
class NestedInteger {
  public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    vector<int> integers;
    int ptr = 0;
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }

    void flatten(vector<NestedInteger> v){ // dfs
        for(int i = 0; i < v.size(); i++){
            if(v[i].isInteger()){
                integers.push_back(v[i].getInteger());
            }else{
                flatten(v[i].getList());
            }
        }
    }
    
    int next() {
        return integers[ptr++];
    }
    
    bool hasNext() {
        return ptr < integers.size();
    }
};