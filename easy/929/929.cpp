#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string, bool> table;
        int ans = 0;
        for(int i = 0; i < emails.size(); i++){
            int pos = emails[i].find('@');
            string localName = emails[i].substr(0, pos);
            string domain = emails[i].substr(pos, emails[i].length()-pos);
            pos = emails[i].find('+');
            if(pos != std::string::npos){
                localName = localName.substr(0, pos);
            }
            localName.erase(std::remove(localName.begin(), localName.end(), '.'), localName.end());
            string addr = localName + domain;
            if(table.count(addr) == 0){
                table[addr] = true;
                ans++;
            }
        }
        return ans;
    }
};