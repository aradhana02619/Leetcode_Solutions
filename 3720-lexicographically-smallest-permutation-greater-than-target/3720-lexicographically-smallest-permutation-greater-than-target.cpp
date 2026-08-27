class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        string current = "";
    
        auto dfs = [&](auto& self, int idx, bool is_greater) -> bool {
            if (idx == n) {
                return is_greater;
            }

            int start_char = 0;

            if (!is_greater) {
                start_char = target[idx] - 'a';
            }

            if (!is_greater && count[start_char] > 0) {
                count[start_char]--;
                current.push_back(start_char + 'a');
                if (self(self, idx + 1, false)) {
                    return true;
                }
               
                current.pop_back();
                count[start_char]++;
            }

            int min_greater = is_greater ? 0 : start_char + 1;
            for (int i = min_greater; i < 26; ++i) {
                if (count[i] > 0) {
                    count[i]--;
                    current.push_back(i + 'a');
                    
                    if (self(self, idx + 1, true)) {
                        return true;
                    }
                
                    current.pop_back();
                    count[i]++;
                }
            }

            return false;
        };

        if (dfs(dfs, 0, false)) {
            return current;
        }
        return "";
    }
};
  