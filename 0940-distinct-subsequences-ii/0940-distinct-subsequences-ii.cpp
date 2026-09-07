class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
    
        vector<long long> endsIn(26, 0);
        long long current_total = 0; 
        
        for (char c : s) {
            int idx = c - 'a';
        
            long long new_ends_in_c = (current_total + 1) % MOD;
            
            current_total = (current_total - endsIn[idx] + new_ends_in_c + MOD) % MOD;
            
            endsIn[idx] = new_ends_in_c;
        }
        
        return current_total;
        
    }
};