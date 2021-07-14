#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    map<int,int> table;
    bool isHappy(int n) {
        while(n != 1){
            n = get_next(n);
            if(table.count(n) > 0){
                return false;
            }
            table[n] = 1;
        }
        return true;
    }
    int get_next(int n){
        int sum = 0;
        while(n > 0){
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }
};