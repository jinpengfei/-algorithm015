class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; ++i)
        {
            res = (res << 1) + (n & 1);
            n >>= 1;
        }
        return res;
    }
};


/*
颠倒给定的 32 位无符号整数的二进制位。
*/
