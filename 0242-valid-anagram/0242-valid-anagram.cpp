class Solution {
public:
    bool isAnagram(string s, string t) {
        int n=s.length();
        int m=t.length();

        if(n!=m){
            return false;
        }

        unordered_map<char,int>freq;

        for(int i=0; i<n; i++){
            if(freq.count(s[i])){
                freq[s[i]]++;
            }
            else{
                freq[s[i]]=1;
            }
        }
        for(int i=0; i<m; i++){
            if(freq.count(t[i])){
                freq[t[i]]--;
            
            if(freq[t[i]]==0)
                freq.erase(t[i]);
            }else{
                return false;
            }
        }
        return freq.size()==0;
    }
};