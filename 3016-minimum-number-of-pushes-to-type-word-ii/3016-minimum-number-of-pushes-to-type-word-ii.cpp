class Solution {
public:
    int minimumPushes(string word) {
        int total_pushes = 0;
        vector<int> count(26, 0);
        
        
        for (char c : word) {
            count[c - 'a']++;
        }
        
        
        sort(count.begin(), count.end(), greater<int>());
        
        
        for (int i = 0; i < 26; ++i) {
            if (count[i] == 0) break;
            int pushes_per_char = (i / 8) + 1;
            total_pushes += count[i] * pushes_per_char;
        }
        
        return total_pushes;
        
    }
};