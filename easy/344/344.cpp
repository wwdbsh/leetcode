#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        queue<char> q;
        while(!s.empty()){
            q.push(s[s.size()-1]);
            s.pop_back();
        }
        while(!q.empty()){
            s.push_back(q.front());
            q.pop();
        }
    }
};