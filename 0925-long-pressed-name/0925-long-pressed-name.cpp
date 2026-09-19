class Solution {
public:
    bool isLongPressedName(string name, string typed) {
       int n=name.length();
       int m=typed.length();
    int i=0, j=0;
       while(i<n && j<m){
        if(name[i]==typed[j]){
            i++;
            j++;
       }

        else if(i>0 && name[i-1]==typed[j]){
            j++;
        }
        else{
            return false;
        }
        } 
        if(i<n){
            return false;
        }
         while(j < m) {
            if(typed[j] != name[i - 1])
                return false;

            j++;
        }

       return true;
    }
};                     