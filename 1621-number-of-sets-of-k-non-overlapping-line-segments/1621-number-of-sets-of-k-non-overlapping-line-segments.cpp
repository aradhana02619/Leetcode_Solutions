class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1'000'000'007;
        
        int N = n + k - 1;
        int R = 2 * k;
        
        if (R > N) return 0;
        

        long long num = 1;
        long long den = 1;
        

        for (int i = 0; i < R; ++i) {
            num = (num * (N - i)) % MOD;
            den = (den * (i + 1)) % MOD;
        }
        
       
        return (num * modularInverse(den, MOD)) % MOD;
    }

private:
   
    long long modularInverse(long long base, long long exp) {
        long long res = 1;
        long long power = exp - 2;
        base = base % exp;
        
        while (power > 0) {
            if (power % 2 == 1) {
                res = (res * base) % exp;
            }
            base = (base * base) % exp;
            power /= 2;
        }
        
        return res;
    }
};
