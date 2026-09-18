class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> leftmost(26, n);
        vector<int> rightmost(26, -1);
        
        
        for (int i = 0; i < n; ++i) {
            leftmost[s[i] - 'a'] = min(leftmost[s[i] - 'a'], i);
            rightmost[s[i] - 'a'] = i;
        }
        
        vector<string> ans;
        int prev_right = -1; 
        for (int i = 0; i < n; ++i) {
           
            if (i != leftmost[s[i] - 'a']) {
                continue;
            }
            
            int curr_right = rightmost[s[i] - 'a'];
            bool valid = true;
            
            for (int j = i; j <= curr_right; ++j) {
              
                if (leftmost[s[j] - 'a'] < i) {
                    valid = false;
                    break;
                }
                curr_right = max(curr_right, rightmost[s[j] - 'a']);
            }
            
            if (!valid) {
                continue;
            }
            
            
            if (curr_right <= prev_right) {
                ans.pop_back();
                ans.push_back(s.substr(i, curr_right - i + 1));
                prev_right = curr_right;
            } 

            else if (i > prev_right) {
                ans.push_back(s.substr(i, curr_right - i + 1));
                prev_right = curr_right;
            }
        }
        
        return ans;
    }
};