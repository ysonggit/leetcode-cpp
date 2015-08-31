// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
     // strcpy terminates when the source string's null terminator is found. 
     // memcpy requires a size parameter be passed
    int read(char *buf, int n) {
        bool eof = false;
        char * temp = new char[4];
        int read_bytes = 0;
        while(!eof){
            int coming_bytes = read4(temp);
            if(coming_bytes < 4) eof = true;
            // mistake : given "a" 0, should not read a into buf
            // neither strcpy(buf+read_bytes, temp); nor strncpy is a good choice, because of a null termnitor
            int bytes_to_copy = min(coming_bytes, n-read_bytes);
            memcpy(buf+read_bytes, temp, bytes_to_copy);
            read_bytes += bytes_to_copy; //mistake : += coming_bytes (not the same as bytes_to_copy)
        }
        // memory 
        delete [] temp;
        temp = NULL;
        return read_bytes;
    }
};
