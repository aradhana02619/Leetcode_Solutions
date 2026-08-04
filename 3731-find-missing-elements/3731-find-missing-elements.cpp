class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        
        vector<int>v;
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        for(int i=nums[0]; i<nums[n-1]; i++){
            if(!(mp.count(i))){
                v.push_back(i);
            }
        }

return v;
        
    }
};