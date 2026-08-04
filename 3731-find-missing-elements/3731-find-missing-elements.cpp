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
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(int i=mn; i<mx; i++){
            if(!(mp.count(i))){
                v.push_back(i);
            }
        }

return v;
        
    }
};