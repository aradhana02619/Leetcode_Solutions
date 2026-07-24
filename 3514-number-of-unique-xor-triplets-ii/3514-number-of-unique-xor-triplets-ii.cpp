class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
    
        int max_val = 0;
        for (int num : nums) {
            max_val = std::max(max_val, num);
        }
    
        int max_xor_limit = 1;
        while (max_xor_limit <= max_val) {
            max_xor_limit <<= 1;
        }
        
        max_xor_limit <<= 1; 

        vector<bool> seen_pairs(max_xor_limit, false);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                seen_pairs[nums[i] ^ nums[j]] = true;
            }
        }


        vector<bool> seen_triplets(max_xor_limit, false);
        int unique_count = 0;

        for (int pair_xor = 0; pair_xor < max_xor_limit; ++pair_xor) {
            if (seen_pairs[pair_xor]) {
                for (int k = 0; k < n; ++k) {
                    int triplet_xor = pair_xor ^ nums[k];
                    if (!seen_triplets[triplet_xor]) {
                        seen_triplets[triplet_xor] = true;
                        unique_count++;
                    }
                }
            }
        }

        return unique_count;
    }
};