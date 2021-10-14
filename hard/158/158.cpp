#include <iostream>

int read4(char *buf4);

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
private:
    int index = 0, limit = 0;
    char *buf4 = new char[4];

public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int i = 0;
        while(i < n){
            if(index < limit) buf[i++] = buf4[index++];
            
            else{
                index = 0;
                limit = read4(buf4);
                if(limit == 0) return i;
            }
        }
        
        return i;
    }
};

