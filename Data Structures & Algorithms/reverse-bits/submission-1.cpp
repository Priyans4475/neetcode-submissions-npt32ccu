class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
 uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;          // Shift result left
        result |= (n & 1);     // Add the last bit of n to result
        n >>= 1;               // Shift n right
    }
    return result;
    }
};
