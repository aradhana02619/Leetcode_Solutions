class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n= nums.size();
        unordered_set<int> s(nums.begin(), nums.end());
        int sequential = nums[0];
        for(int i=1; i<n; i++){
        if(nums[i]==nums[i-1]+1){
           sequential+=nums[i];
            }
            else{
                break;
            }
        }
        while(s.count(sequential)){
            sequential++;
        }
        return sequential;
    }
};