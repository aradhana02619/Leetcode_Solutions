class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // sort(begin(nums), end(nums));
       int n = nums.size();
       int mn=nums[0];
       int mx=nums[0];
        for(int i=1; i<n; i++){
           mn = min(mn, nums[i]);
           mx = max(mx, nums[i]); 
        }
        
        vector<int>v;
        unordered_set<int>st(begin(nums), end(nums));
        
        for(int i=mn; i<mx; i++){
            if(st.find(i)==st.end()){
                v.push_back(i);
            }
        }

return v;
        
    }
};