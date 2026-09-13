class Solution {
public:

    int countOverlaps(vector<vector<int>>& img1, vector<vector<int>>& img2, int rowOff, int colOff ){
        int n = img1.size();
        int count = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
             int img2_i = i+rowOff;
             int img2_j = j+colOff;

             if(img2_i < 0 || img2_i>=n || img2_j<0 || img2_j>=n)
               continue;

            if(img1[i][j]==1 && img2[img2_i][img2_j] == 1)
             count++;
            }
        }
        return count;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        int maxOverlap = 0;

        for(int rowOff = -n+1; rowOff<n; rowOff++){
            for(int colOff = -n+1; colOff<n; colOff++){
                int count = countOverlaps(img1, img2, rowOff, colOff);
                maxOverlap=max(maxOverlap, count);
            }  
        }
        return maxOverlap;
        
    }
};