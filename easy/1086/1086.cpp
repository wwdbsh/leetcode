#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <map>

using namespace std;

int compare(vector<int> a, vector<int> b){
    return a[1] > b[1];
}

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        sort(items.begin(), items.end(), compare);
        map<int, pair<int,int>> hashMap;
        for(int i = 0; i < items.size(); i++){
            if(hashMap[items[i][0]].second < 5){
                hashMap[items[i][0]].first += items[i][1];
                hashMap[items[i][0]].second++;
            }
        }
        vector<vector<int>> result;
        for(map<int, pair<int,int>>::iterator it = hashMap.begin(); it != hashMap.end(); it++){
            result.push_back({it->first, it->second.first/5});
        }
        return result;
    }
};