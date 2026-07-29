class Solution {
private:
    
    long long countPermutations(const vector<int>& freq, int totalLength) {
        if (totalLength == 0) return 1;
        
        
        double permutations = 1.0;
        int current_len = 1;
        
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= freq[i]; ++j) {
                permutations = permutations * current_len / j;
                current_len++;
            }
        }
        
       
        if (permutations > 2e18) return 2e18; 
        return (long long)permutations;
    }

public:
    string smallestPalindrome(string s, long long k) {
        vector<int> total_freq(26, 0);
        for (char c : s) {
            total_freq[c - 'a']++;
        }

        
        int odd_count = 0;
        char mid_char = '*';
        vector<int> half_freq(26, 0);
        
        for (int i = 0; i < 26; ++i) {
            if (total_freq[i] % 2 != 0) {
                odd_count++;
                mid_char = (char)('a' + i);
            }
            half_freq[i] = total_freq[i] / 2;
        }

        
        if (odd_count > 1) return "";

        int half_len = s.length() / 2;
        
        
        if (countPermutations(half_freq, half_len) < k) {
            return "";
        }

        string first_half = "";
        int remaining_slots = half_len;

       
        for (int pos = 0; pos < half_len; ++pos) {
            for (int i = 0; i < 26; ++i) {
                if (half_freq[i] > 0) {
                    
                    half_freq[i]--;
                    remaining_slots--;

                    long long options = countPermutations(half_freq, remaining_slots);

                    if (k <= options) {
                        
                        first_half += (char)('a' + i);
                        break;
                    } else {
                        
                        k -= options;
                        
                        half_freq[i]++;
                        remaining_slots++;
                    }
                }
            }
        }

       
        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());

        if (mid_char != '*') {
            return first_half + mid_char + second_half;
        }
        return first_half + second_half;
    }
};