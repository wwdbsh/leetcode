#include <iostream>
#include <iterator>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> keyMap;
        for(int i = 0; i < s.length(); i++){
            if(keyMap.count(s[i]) > 0){
                keyMap[s[i]]++;
            }else{
                keyMap[s[i]] = 1;
            }
        }
        for(int i = 0; i < t.length(); i++){
            if(keyMap.count(t[i]) > 0 && keyMap[t[i]] > 0){
                keyMap[t[i]]--;
            }else{
                return false;
            }
        }
        for(map<char,int>::iterator it = keyMap.begin(); it != keyMap.end(); it++){
            if(it->second != 0){
                return false;
            }
        }
        return true;
    }
};