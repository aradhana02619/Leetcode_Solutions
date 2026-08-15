class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int srow = 0;
        int scol = 0;
        int erow = n-1;
        int ecol = m-1;
   vector<int>ans;
        while(srow<=erow && scol<=ecol){
            for(int j=scol; j<=ecol; j++){
                ans.push_back(matrix[srow][j]);
            }
            for(int i=srow+1; i<=erow; i++){
                ans.push_back(matrix[i][ecol]);
            }
            for(int j=ecol-1; j>=scol; j--){
                 if(srow==erow){
                    break;
                }
                ans.push_back(matrix[erow][j]);
            }
            for(int i=erow-1; i>=srow+1; i--){
                if(scol==ecol){
                    break;
                }
                ans.push_back(matrix[i][scol]);
            }
           srow++;
           scol++;
           erow--;
           ecol--;
        }
        return ans;
    }
};