class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        for(int i=0; i<32; i++){ // mistake: while(n>0)
            uint32_t mask = (1<<i);
            auto bit = (mask & n)>>i;
            rev |= (bit<<(31-i));
        }
        return rev;
    }
};
