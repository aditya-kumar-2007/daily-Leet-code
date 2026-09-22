class Solution {
public:
    int divide(int a, int b) {
        if (a == INT_MIN && b == -1)
         return INT_MAX;
        long long x = abs((long long)a), y = abs((long long)b), r = 0;
        while (x >= y) {
            long long t = y, m = 1;
            while (x >= (t << 1)) 
            t <<= 1, m <<= 1;
            x -= t, r += m;
        }
        return ((a < 0) ^ (b < 0)) ? -r : r;
    }
};