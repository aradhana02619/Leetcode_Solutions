class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
      sort(begin(strs), end(strs));

    string st="";
    string first = strs[0];
    string last = strs[n-1];
    int mn = min(strs[0].length(), strs[n-1].length());
    for(int i=0; i<mn; i++){
        if(first[i]==last[i]){
            st+=first[i];
        }
        else{
            break;
        }
     }
    

       return st; 
        
    }
};