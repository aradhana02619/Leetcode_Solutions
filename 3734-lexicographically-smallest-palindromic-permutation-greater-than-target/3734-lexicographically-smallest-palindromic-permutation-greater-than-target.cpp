class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = 'a' + i;
            }
        }

        if (odd > 1)
            return "";

    
        vector<int> half(26);
        for (int i = 0; i < 26; i++)
            half[i] = cnt[i] / 2;

        int m = n / 2;

        string left;

        auto makePalindrome = [&](string L) {
            string res = L;

            if (n % 2)
                res += mid;

            for (int i = (int)L.size() - 1; i >= 0; i--)
                res += L[i];

            return res;
        };


        auto possible = [&]() -> bool {

            string candidate = left;

            for (int c = 25; c >= 0; c--) {
                candidate += string(half[c], char('a' + c));
            }

            string palindrome = makePalindrome(candidate);

            return palindrome > target;
        };

        for (int pos = 0; pos < m; pos++) {

            bool found = false;

        
            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;
                left.push_back('a' + c);

        
                if (possible()) {
                    found = true;
                    break;
                }

                
                left.pop_back();
                half[c]++;
            }

            if (!found)
                return "";
        }

        string ans = makePalindrome(left);

        if (ans > target)
            return ans;

        return "";
    }
};