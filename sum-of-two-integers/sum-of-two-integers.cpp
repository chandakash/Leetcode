class Solution {
public:
    int getSum(int a, int b) {
    
        while(b) // till there is a carry.
        {
            int carry = (unsigned int)(a&b)<<1; //left shift the carry and add it to sum.
            a = a^b; // xor of a and b.
            b = carry;
        }
    return a;
    }
};