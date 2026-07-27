class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        for(int x : nums){
            if(x>max1){
                max2=max1;
                max1=x;
            }
          else if(x>max2){
                max2=x;
            }
            
        }
        int ans = (max1-1)*(max2-1);

        return ans;
        
    }
};