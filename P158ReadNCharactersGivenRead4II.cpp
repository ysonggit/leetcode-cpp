// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    char buffer [4];
    int offset =0, bufsize = 0;
    int read(char *buf, int n) {
        bool eof = false;
        int bytes_copied = 0;
        while(bytes_copied< n && !eof){
            if(bufsize==0){
                bufsize = read4(buffer);
                eof = bufsize < 4;
            }
            int bytes_to_copy = min(n-bytes_copied, bufsize);
            //memcpy( void* dest, const void* src, std::size_t count );
            memcpy(buf+bytes_copied, buffer+offset, bytes_to_copy);
            offset = (offset+bytes_to_copy)%4;
            bytes_copied += bytes_to_copy;
            bufsize -= bytes_to_copy;
        }
        return bytes_copied;
    }
};
