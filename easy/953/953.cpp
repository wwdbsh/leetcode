#include <iostream>
#include <vector>

using namespace std;

int w[26];

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < order.length(); i++){
            w[(int)(order[i]-'a')] = i;
        }
        for(int i = 0; i < words.size()-1; i++){
            for(int j = 0; j < words[i].length(); j++){
                if(j >= words[i+1].length()){
                    return false;
                }
                if(words[i][j] != words[i+1][j]){
                    if(w[(int)(words[i][j]-'a')] > w[(int)(words[i+1][j]-'a')]){
                        return false;
                    }
                    break;
                }
            }
        }
        return true;
    }
};