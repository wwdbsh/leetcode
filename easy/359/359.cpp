#include <iostream>
#include <map>

using namespace std;

class Logger {
public:
    map<string,int> table;
    Logger() {
        
    }
    bool shouldPrintMessage(int timestamp, string message) {
        if(table.count(message) > 0){
            if(table[message] > timestamp){
                return false;
            }
        }
        table[message] = 10 + timestamp;
        return true;
    }
};